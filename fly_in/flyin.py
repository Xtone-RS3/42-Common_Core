from collections import defaultdict
import heapq
import sys
from typing import Any, Dict, Tuple


reservations: Dict[str, Dict[Tuple, int]] = {
    "nodes": {},   # (cell_name, time) -> drone_id
    "edges": {}    # (from_name, to_name, time) -> drone_id
}


# Define the Cell class
class Cell:
    def __init__(self):
        self.name = ""
        self.color = ""
        self.max_drones = 1  # default
        self.zone_type = None
        self.is_start = False
        self.is_end = False
        self.connections = {}
        self.x = 0
        self.y = 0
        self.parent = None
        self.parent_i = 0
        self.parent_j = 0

    def print_data(self):
        print(
            "name:", self.name, "color:", self.color, "max:", self.max_drones,
            "zone:", self.zone_type,
            "coords[", self.parent_i, self.parent_j, "]"
        )

    def get_connections(self):
        return self.connections


def is_destination(row, col, dest):
    return row == dest[0] and col == dest[1]


def calculate_h_value(curr_cell, dest):
    return ((curr_cell.x - dest.x) ** 2 + (curr_cell.y - dest.y) ** 2) ** 0.5


def reconstruct_path(
        parent, goal_name, goal_time, cell_lookup, reservations, drone_id
):
    path = []
    state = (goal_name, goal_time)
    stuck = False

    while state in parent:
        cell_name, time = state
        if parent[state][0] == state[0]:
            stuck = True
        if stuck is False:
            path.append((cell_lookup[cell_name], time))
        else:
            stuck = False
        if cell_lookup[cell_name].zone_type == "restricted":
            path.append((cell_lookup[cell_name], time-1))
        state = parent[state]

    # add start
    cell_name, time = state
    path.append((cell_lookup[cell_name], time))

    path.reverse()
    # reserve path
    for i, (cell, t) in enumerate(path):
        reservations["nodes"][(cell.name, t)] =\
            reservations["nodes"].get((cell.name, t), 0) + 1
        if i > 0:
            prev_cell, _ = path[i-1]
            reservations["edges"][(prev_cell.name, cell.name, t)] =\
                reservations["edges"].get((prev_cell.name, cell.name, t), 0)+1

    print(f"Drone {drone_id+1} path:")
    for cell, t in path:
        print(f"{cell.name}@{t+1}", end=" -> ")
    print()
    return path


def a_star_search(map, reservations, drone_id, time_offset=0):
    # find src and dest
    for cell in map:
        if cell.is_start:
            src = cell
        if cell.is_end:
            dest = cell

    open_list = []
    heapq.heappush(open_list, (0, time_offset, src.name))
    # (f, time, cell_name)

    g_score = {(src.name, time_offset): 0}
    parent = {}

    # i wont go insane from having to re-write the same comprehension 50 times
    cell_lookup = {cell.name: cell for cell in map}

    while open_list:
        f, time, cell_name = heapq.heappop(open_list)

        if (cell_name, time) not in g_score:
            continue

        curr_cell = cell_lookup[cell_name]

        # GOAL CHECK
        if curr_cell.is_end:
            return reconstruct_path(
                parent, cell_name, time, cell_lookup, reservations, drone_id
            )

        # --- MOVE TO NEIGHBORS ---
        for neighbor_name, neighbor_cell in curr_cell.connections.items():
            next_time = time + 1
            # reservation checks
            current_count =\
                reservations["nodes"].get((neighbor_name, next_time), 0)

            if neighbor_cell.zone_type == "restricted":
                next_time += 1  # spend extra timestep inside node

            if current_count >= neighbor_cell.max_drones:
                return a_star_search(
                    map, reservations, drone_id, time_offset+1
                )

            if (neighbor_name, cell_name, next_time) in reservations["edges"]:
                continue

            # movement cost
            if neighbor_cell.zone_type == "restricted":
                move_cost = 2.0
            elif neighbor_cell.zone_type == "priority":
                move_cost = 0.5
            else:
                move_cost = 1.0
            occupancy =\
                reservations["nodes"].get((neighbor_name, next_time), 0)
            move_cost += occupancy

            tentative_g = g_score[(cell_name, time)] + move_cost
            state = (neighbor_name, next_time)

            if state not in g_score or tentative_g < g_score[state]:
                g_score[state] = tentative_g
                parent[state] = (cell_name, time)

                h = calculate_h_value(neighbor_cell, dest)
                f_new = tentative_g + h

                heapq.heappush(open_list, (f_new, next_time, neighbor_name))

        # --- WAIT ACTION ---
        if (cell_name, next_time) not in reservations["nodes"]:
            tentative_g = g_score[(cell_name, time)] + 1
            state = (cell_name, next_time)

            if state not in g_score or tentative_g < g_score[state]:
                g_score[state] = tentative_g
                parent[state] = (cell_name, time)

                h = calculate_h_value(curr_cell, dest)
                f_new = tentative_g + h

                heapq.heappush(open_list, (f_new, next_time, cell_name))

    print("Failed to find path for drone", drone_id)
    return None


if __name__ == "__main__":
    # TODO PLEASE REMEMBER TO CHECK IF MAKEFILE LINT WORKS!!!!!!!!
    map = []
    nb_drones = 0
    path_taken = {}
    parse_credits: dict[str, Any] = {
        "nodes": 0,
        "start_node": False,
        "end_node": False,
        "drone_nb": 0,
        "node_names": [],
        "valid_zones": ["normal", "blocked", "restricted", "priority"],
        "valid_node_metadata": ["color", "zone", "max_drones"],
        "curr_connections": []
    }
    try:
        with open(sys.argv[1]) as file:
            map_info = file.read().split("\n")
            for line in map_info:
                if line.startswith("nb_drones: "):
                    nb_drones = int(line.split(": ")[1])
                    parse_credits["drone_nb"] = nb_drones
                if line.startswith(("start_hub", "hub", "end_hub")):
                    map.append(Cell())
                    curr_cell = map[len(map)-1]
                    data = line.split(": ")
                    if data[0] == "start_hub":
                        if parse_credits["start_node"] is True:
                            raise Exception(
                                "Parsing issue, too many start hubs"
                            )
                        curr_cell.is_start = True
                        curr_cell.max_drones = 1024
                        parse_credits["start_node"] = True
                    if data[0] == "end_hub":
                        if parse_credits["end_node"] is True:
                            raise Exception(
                                "Parsing issue, too many end hubs"
                            )
                        curr_cell.is_end = True
                        curr_cell.max_drones = 1024
                        parse_credits["end_node"] = True
                    data = data[1].split(' ', 3)
                    curr_cell.name = data[0]
                    if curr_cell.name.__contains__("-") or\
                            curr_cell.name.__contains__(" "):
                        raise Exception("Invalid node name, contains a dash")
                    if curr_cell.name in parse_credits["node_names"]:
                        raise Exception("Duplicated node name")
                    parse_credits["node_names"].append(curr_cell.name)
                    curr_cell.x = int(data[1])
                    curr_cell.y = int(data[2])
                    parse_credits["nodes"] += 1
                    data = data[3].strip("[]").split(" ")
                    for item in data:
                        if item.split("=")[0] not in\
                                parse_credits["valid_node_metadata"]:
                            raise Exception(
                                f"Bad parsing syntax: {item.split("=")[0]}"
                            )
                    for field in data:
                        if field.startswith("color="):
                            curr_cell.color = field.split("=")[1]
                        if field.startswith("max_drones="):
                            if int(field.split("=")[1]) <= 0:
                                raise Exception(
                                    f"Invalid max_drones: {
                                        int(field.split("=")[1])
                                    }"
                                )
                            curr_cell.max_drones = int(field.split("=")[1])
                        if field.startswith("zone="):
                            if field.split("=")[1] not in\
                                    parse_credits["valid_zones"]:
                                raise Exception(
                                    f"Incorrect zone: {field.split("=")[1]}"
                                )
                            curr_cell.zone_type = field.split("=")[1]
                elif line.startswith("connection"):
                    connection = line.split(": ")[1].replace(" ", "-")
                    connection_list = connection.split("-")
                    if (connection_list[0], connection_list[1]) in\
                            parse_credits["curr_connections"]:
                        raise Exception(
                            f"Duplicate connection between: {
                                connection_list[0]
                            } and {
                                connection_list[1]
                            }"
                        )
                    cell1 = map[
                        next((i for i, cell in enumerate(map)
                              if cell.name == connection_list[0]), -1)
                    ]
                    cell2 = map[next((i for i, cell in enumerate(map)
                                      if cell.name == connection_list[1]), -1)]
                    parse_credits["curr_connections"].append(
                        (connection_list[0], connection_list[1])
                    )
                    parse_credits["curr_connections"].append(
                        (connection_list[1], connection_list[0])
                    )
                    max_link_capacity = -1
                    if len(connection_list) >= 3:
                        max_link = connection_list[2].strip("[]").split("=")[1]
                        if connection_list[2].strip("[]").split("=")[0] !=\
                                "max_link_capacity":
                            raise Exception(
                                f"Bad parsing syntax: {
                                    connection_list[2].strip("[]").split("=")
                                    [0]
                                }"
                            )
                        if int(line.strip("]").split()[2].split(
                            "[max_link_capacity="
                        )[1]) <= 0:
                            raise Exception(
                                f"Invalid max_link_capacity: {
                                    int(line.strip("]").split()[2].split(
                                        "[max_link_capacity="
                                    )[1])
                                }"
                            )
                        max_link_capacity =\
                            int(max_link)
                    cell1.connections[cell2.name] = cell2
            for cell in map:
                if cell.is_start:
                    src = cell
                if cell.is_end:
                    dest = [cell.parent_i, cell.parent_j]
        if parse_credits["drone_nb"] <= 0:
            raise Exception(
                f"Invalid number of drones: {parse_credits["drone_nb"]}"
            )
        if parse_credits["nodes"] <= 3:
            raise Exception("Too few nodes")
        if parse_credits["start_node"] is False:
            raise Exception("Missing start node")
        if parse_credits["end_node"] is False:
            raise Exception("Missing end node")
        print("==============================================================")
        print("Smart way to print path:")
        print("==============================================================")
        for drone_id in range(nb_drones):
            path_taken[drone_id] = a_star_search(map, reservations, drone_id)
        print("==============================================================")
        print("Silly way to print path:")
        print("==============================================================")
        turns = defaultdict(list)
        for drone, moves in path_taken.items():
            for cell, turn in moves:
                turns[turn].append((drone, cell))
        path_taken = dict(sorted(turns.items()))
        for turn in turns:
            movements = []
            for drone, cell in path_taken[turn]:
                name = cell.name
                movements.append(f"D{drone+1}-{name}")
            print(f"Turn {turn+1}\n-> ", end="")
            print(" ".join(movements))
    except Exception as e:
        print(e)
