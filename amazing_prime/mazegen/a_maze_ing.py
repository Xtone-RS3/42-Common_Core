import sys
import random
from mlx import Mlx


class ImgData:
    """Structure for image data"""
    def __init__(self):
        self.img = None
        self.width = 0
        self.height = 0
        self.data = None
        self.sl = 0
        self.bpp = 0
        self.iformat = 0


class XVar:
    """Structure for main vars"""
    def __init__(self):
        self.mlx = None
        self.mlx_ptr = None
        self.screen_w = 0
        self.screen_h = 0
        self.win = None
        self.imgidx = 0
        self.default_maze = None
        self.width = 0
        self.height = 0
        self.block_size = 0
        self.entry = []
        self.exit = []

    def get_screen_sizes(self):
        """
        gets window size, might be handy in the future to have the window
        perfectly fit window and retroactively scale to maze_size-win_size
        """
        return self.win

    def set_maze(self, mazeing):
        """
        sets the default_maze value for later use within xvar stuff
        """
        self.default_maze = mazeing

    def get_default_maze(self):
        return self.default_maze

    def set_default_info(
            self, width, height, block_size, entry, exit, perfect
    ):
        self.width = width
        self.height = height
        self.block_size = block_size
        self.entry = entry
        self.exit = exit
        self.perfect = perfect

    def get_default_info(self):
        return [
            self.width * self.height,
            self.width,
            self.height,
            self.block_size,
            self.entry,
            self.exit,
            self.perfect
        ]

    def block_size_math(self, height, width):
        """
        calculates the maximum block_size to have the window fully fill the\
            screen, while also not being way big for smaller mazes
        """
        max_y = 989/height
        max_x = 1920/width
        return min(max_x, max_y, 32)


def draw_north_wall(xvar, coord_x, coord_y, size, color):
    edge = max(int(size * 0.07), 1)
    for y in range(edge):
        for x in range(size):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_west_wall(xvar, coord_x, coord_y, size, color):
    edge = max(int(size * 0.07), 1)
    for y in range(size):
        for x in range(edge):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_east_wall(xvar, coord_x, coord_y, size, color):
    edge = max(int(size * 0.07), 1)
    for y in range(size):
        for x in range(size-edge, size):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_south_wall(xvar, coord_x, coord_y, size, color):
    edge = max(int(size * 0.07), 1)
    for y in range(size-edge, size):
        for x in range(size):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_fourty_two(xvar, coord_x, coord_y, size, color):
    for y in range(size):
        for x in range(size):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_enter(xvar, coord_x, coord_y, size, color):
    """
    entry and path
    """
    margin = max(int(size * 0.11), 1)
    # i want to change it to work with lines, not dots
    for y in range(int(size/2)-margin, int(size/2)+margin):
        for x in range(int(size/2)-margin, int(size/2)+margin):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def draw_end(xvar, coord_x, coord_y, size, color):
    margin = max(int(size * 0.11), 1)
    for y in range(int(size/2)-margin, int(size/2)+margin):
        for x in range(int(size/2)-margin, int(size/2)+margin):
            xvar.mlx.mlx_pixel_put(
                xvar.mlx_ptr,
                xvar.win,
                x+coord_x*size,
                y+coord_y*size,
                color
            )


def gere_key(key, xvar):
    if key == 49:
        [
            size, width, height, block_s, entry, exit, perfect
        ] = xvar.get_default_info()
        lol = MazeGenerator(
            size, width, height, block_s, entry, exit, default_path=[],
            perfect=perfect
        )
        xvar.set_maze(lol)
        lol.maze_carver(entry[0], entry[1])
        xvar.mlx.mlx_clear_window(xvar.mlx_ptr, xvar.win)
        with open(output_file, "w") as out_file:
            out_file.write(xvar.get_default_maze().printMaze())
            out_file.write(xvar.get_default_maze().print_default_path(True))
            print("saved to file")
        xvar.get_default_maze().printMlx(xvar)
        return 0

    if key == 50:
        xvar.mlx.mlx_clear_window(xvar.mlx_ptr, xvar.win)
        xvar.get_default_maze().toggle_solution_visible()
        xvar.get_default_maze().printMlx(xvar)
        return 0

    if key == 51:
        xvar.get_default_maze().next_color()
        xvar.mlx.mlx_clear_window(xvar.mlx_ptr, xvar.win)
        xvar.get_default_maze().printMlx(xvar)
        return 0

    if key == 52 or key == 65307:
        win_close(xvar)
        return 0


# class Solver(object):
#     """
#     BUSTED SOLVER CLASS THAT I NEED TO FIX
#     """
#     def __init__(self, maze):
#         self.path = []
#         self.maze = {
#             k: {kk: (False if vv is True and kk == "visited" else vv) for kk,
#                 vv in v.items()}
#             for k, v in maze.items()
#         }

#     def solve(self, entry, exit):
#         """
#         docstring
#         """
#         [x, y] = entry
#         while [x, y] != exit:
#             print(x, y)
#             if self.maze[(x, y)]["west"] == 0\
#                     and self.maze[(x, y)]["visited"] is False:
#                 print("west")
#                 x -= 1
#                 self.path.append((x, y))
#             if self.maze[(x, y)]["east"] == 0\
#                     and self.maze[(x, y)]["visited"] is False:
#                 print("east")
#                 x += 1
#                 self.path.append((x, y))
#             if self.maze[(x, y)]["south"] == 0\
#                     and self.maze[(x, y)]["visited"] is False:
#                 print("south")
#                 y += 1
#                 self.path.append((x, y))
#             if self.maze[(x, y)]["north"] == 0\
#                     and self.maze[(x, y)]["visited"] is False:
#                 print("north")
#                 y -= 1
#                 self.path.append((x, y))
#             print(x, y)
#         return self.path


def reverse_bit_math(input):
    """
    Takes an hex and splits its parts into the corresponding maze wall bits,
    also takes care of entry, exit, and solution
    """
    maze = {}
    width = 0
    height = 0
    entry = []
    exit = []
    path = []
    x_coord = 0
    y_coord = 0
    ending_entries = 0
    prev = ""
    n = 0
    with open(input, "r") as file:
        for y in file:
            for x in y:
                if prev == "\n" and x == "\n":
                    break
                if x == ",":
                    raise Exception("Corrupted seed!")
                if x != "\n":
                    hex = int(x, 16)
                    maze[(x_coord, y_coord)] = {
                        "west": 1,
                        "south": 1,
                        "east": 1,
                        "north": 1,
                        "visited": False,
                        "42": False
                    }
                    maze[(x_coord, y_coord)]["west"] = int((hex/8) % 2)
                    maze[(x_coord, y_coord)]["south"] = int((hex/4) % 2)
                    maze[(x_coord, y_coord)]["east"] = int((hex/2) % 2)
                    maze[(x_coord, y_coord)]["north"] = hex % 2
                    maze[(x_coord, y_coord)]["visited"] = True
                if x == "\n":
                    if width != 0 and x_coord != width:
                        raise Exception("Corrupted seed!")
                    width = x_coord
                    x_coord = 0
                else:
                    x_coord += 1
                prev = x
            else:
                if x == "\n":
                    y_coord += 1
                continue
            height = y_coord
            break
        for line in file:
            try:
                thing = line.split()
            except Exception as e:
                print("Seed parsing error: ", e)
            if ending_entries == 0:
                ending_entries += 1
                hold = thing[0].split(",")
                entry = [int(hold[0]), int(hold[1])]
                continue
            if ending_entries == 1:
                ending_entries += 1
                hold = thing[0].split(",")
                exit = [int(hold[0]), int(hold[1])]
                continue
            if ending_entries == 2:
                path.append(entry)
                for direction in thing[0]:
                    n += 1
                    if direction == "N":
                        path.append((path[n-1][0], path[n-1][1]-1))
                    elif direction == "S":
                        path.append((path[n-1][0], path[n-1][1]+1))
                    elif direction == "E":
                        path.append((path[n-1][0]+1, path[n-1][1]))
                    elif direction == "W":
                        path.append((path[n-1][0]-1, path[n-1][1]))
                    else:
                        raise Exception("Corrupted seed!", int(direction))
                path.pop()
    return [width, height, entry, exit, path, maze]


class MazeGenerator(object):  # this need to be in a standalone module
    """
    Maze generator with a built-in depth-first algorithm
    """
    def __init__(
            self,
            size,
            width,
            height,
            block_size,
            entry,
            exit,
            perfect=True,
            seed=0,
            default_path=[],
            maze={}
    ):
        self.size = size
        self.seed = seed
        self.width = width
        self.height = height
        self.entry = entry
        self.exit = exit
        self.perfect = perfect
        print(self.perfect)
        self.block_size = block_size
        self.solution_visible = False
        self.visit_count = 0
        self.default_path = default_path
        self.hasVisited = []
        self.two = [
            (1, 0), (2, 0), (3, 0), (3, -1), (3, -2), (2, -2), (1, -2),
            (1, 1), (1, 2), (2, 2), (3, 2)
        ]
        self.four = [
            (-1, 0), (-2, 0), (-3, 0), (-3, -1), (-3, -2), (-1, 1), (-1, 2)
        ]
        self.colors = [
            [0xFF1C73FF, 0xFFFF1CE5, 0xFFFFA81C, 0xFF1CFF36],
            [0xFF1CF0FF, 0xFF9D1CFF, 0xFFFF2B1C, 0xFF7EFF1C],
            [0xFFFF1C1C, 0xFF8EFF1C, 0xFF1CFFFF, 0xFF8E1CFF],
            [0xFFFF1CAC, 0xFFFFE11C, 0xFF1CFF6F, 0xFF1C3AFF]
        ]
        self.curr_color = 0
        if seed == 0:
            self.maze = {}
            for x in range(width):
                for y in range(height):
                    self.maze[(x, y)] = {
                        "west": 1,
                        "south": 1,
                        "east": 1,
                        "north": 1,
                        "visited": False,
                        "42": False
                    }
                    if [x, y] == self.entry:
                        self.maze[(x, y)]["visited"] = True
            if self.perfect is False:
                x = int(self.width/2)
                y = int(self.height/2)
                nw = (x-3, y-2)
                self.maze[nw]["east"] = 0
                self.maze[nw]["south"] = 0
                ne = (x-2, y-2)
                self.maze[ne]["west"] = 0
                self.maze[ne]["south"] = 0
                sw = (x-3, y-1)
                self.maze[sw]["north"] = 0
                self.maze[sw]["east"] = 0
                se = (x-2, y-1)
                self.maze[se]["north"] = 0
                self.maze[se]["west"] = 0
        else:
            self.maze = maze
        self.fourty_two()

    def toggle_solution_visible(self):
        if self.solution_visible is True:
            self.solution_visible = False
        else:
            self.solution_visible = True

    def next_color(self):
        """
        Changes color to next
        """
        self.curr_color += 1
        if self.curr_color >= len(self.colors):
            self.curr_color = 0

    def fourty_two(self):
        two_x = int(self.width/2)
        four_x = int(self.width/2)
        y = int(self.height/2)
        if self.width % 2 == 0:
            four_x -= 1
        for two_coords in self.two:
            self.maze[
                (two_x + two_coords[0], y + two_coords[1])
            ]["42"] = True
        for four_coords in self.four:
            self.maze[
                (four_x + four_coords[0], y + four_coords[1])
            ]["42"] = True

    def bit_math(self, x, y) -> str:
        """
        This method will take the bits on the maze and math out what hex value
        it should be
        """
        hex = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B",
               "C", "D", "E", "F"]
        result = self.maze[(x, y)]["west"] * 2 * 2 * 2
        result += self.maze[(x, y)]["south"] * 2 * 2
        result += self.maze[(x, y)]["east"] * 2
        result += self.maze[(x, y)]["north"]
        return hex[result]

    def printMaze(self):
        """Displays the maze data structure in the maze argument. The
        markX and markY arguments are coordinates of the current
        '@' location of the algorithm as it generates the maze."""
        result = ""
        for y in range(height):
            for x in range(width):
                print(self.bit_math(x, y), end='')
                result += self.bit_math(x, y)
            print()
            result += "\n"
        print()
        result += "\n"
        print(f"{self.entry[0]},{self.entry[1]}")
        result += f"{self.entry[0]},{self.entry[1]}\n"
        print(f"{self.exit[0]},{self.exit[1]}")
        result += f"{self.exit[0]},{self.exit[1]}\n"
        return result

    def printMlx(self, xvar):
        """
        displays the maze using MLX on screen
        """
        size = self.block_size  # NEEDS TO CHANGE RETROACTIVELY WITH win SIZE
        color = self.colors[self.curr_color]
        for y in range(height):
            for x in range(width):
                if self.maze[(x, y)]["north"] == 1:
                    draw_north_wall(xvar, x, y, size, color[0])
                if self.maze[(x, y)]["south"] == 1:
                    draw_south_wall(xvar, x, y, size, color[0])
                if self.maze[(x, y)]["east"] == 1:
                    draw_east_wall(xvar, x, y, size, color[0])
                if self.maze[(x, y)]["west"] == 1:
                    draw_west_wall(xvar, x, y, size, color[0])
                if [x, y] == self.entry:
                    draw_enter(xvar, x, y, size, color[3])
                if [x, y] == self.exit:
                    draw_end(xvar, x, y, size, color[1])
                if self.maze[(x, y)]["42"] is True:
                    draw_fourty_two(xvar, x, y, size, color[2])
                if self.solution_visible:
                    if (x, y) in self.default_path:
                        draw_enter(xvar, x, y, size, color[3])
        xvar.mlx.mlx_string_put(
            xvar.mlx_ptr,
            xvar.win,
            0,
            self.height*size+10,
            color[0],
            "1: regen; 2: path; 3: color; 4: quit"
        )

    def find_neighbours(self, x, y) -> list:
        """
        Finds valid neighbours of the cell at [x, y] and returns a dict with
        [(x, y), wall]
        """
        result = []

        def validator(self, new_x, new_y, demolished_wall):
            if new_x >= 0 and new_y >= 0 and new_x < self.width\
                    and new_y < self.height:
                try:
                    new = self.maze[(new_x, new_y)]
                    if new["visited"] is False and new["42"] is False:
                        result.append([(new_x, new_y), demolished_wall])
                except Exception as e:
                    print("neighbour validator error: ", e)

        validator(self, x+1, y, "ew")
        validator(self, x, y+1, "sn")
        validator(self, x-1, y, "we")
        validator(self, x, y-1, "ns")

        if len(result):
            return result
        else:
            return None

    def maze_carver(self, x, y):  # depth-first
        """
        Carves the 'wall only' maze into a real maze
        """
        ended = False
        while self.visit_count < self.size:
            next_possible_cell = self.find_neighbours(x, y)
            if [x, y] == self.exit:
                ended = True
            if next_possible_cell is not None:
                self.hasVisited.append((x, y))
                if ended is False and self.seed == 0:
                    self.default_path.append((x, y))
                [(next_x, next_y), wall] = random.choice(next_possible_cell)
                if wall.startswith("s"):
                    self.maze[(x, y)]["south"] = 0
                    self.maze[(next_x, next_y)]["north"] = 0
                elif wall.startswith("n"):
                    self.maze[(x, y)]["north"] = 0
                    self.maze[(next_x, next_y)]["south"] = 0
                elif wall.startswith("e"):
                    self.maze[(x, y)]["east"] = 0
                    self.maze[(next_x, next_y)]["west"] = 0
                elif wall.startswith("w"):
                    self.maze[(x, y)]["west"] = 0
                    self.maze[(next_x, next_y)]["east"] = 0
                self.maze[(next_x, next_y)]["visited"] = True
                x = next_x
                y = next_y
                self.visit_count += 1
            elif len(self.hasVisited) > 0:
                (x, y) = self.hasVisited.pop()
                if ended is False and self.seed == 0:
                    (x, y) = self.default_path.pop()
            elif next_possible_cell is None and len(self.hasVisited) == 0:
                return

    def get_maze(self):
        """
        returns the working maze
        """
        return self.maze

    def print_default_path(self, instructions=False):
        """
        prints the default path calculated to solve the maze
        """
        result = ""
        if instructions is True:
            coords = self.default_path
            for n in range(len(coords)):
                try:
                    if coords[n][0]-coords[n+1][0] == 1:
                        print("W", end="")
                        result += "W"
                    if coords[n][0]-coords[n+1][0] == -1:
                        print("E", end="")
                        result += "E"
                    if coords[n][1]-coords[n+1][1] == 1:
                        print("N", end="")
                        result += "N"
                    if coords[n][1]-coords[n+1][1] == -1:
                        print("S", end="")
                        result += "S"
                except Exception:
                    if coords[n][0]-self.exit[0] == 1:
                        print("W")
                        result += "W"
                    if coords[n][0]-self.exit[0] == -1:
                        print("E")
                        result += "E"
                    if coords[n][1]-self.exit[1] == 1:
                        print("N")
                        result += "N"
                    if coords[n][1]-self.exit[1] == -1:
                        print("S")
                        result += "S"
        else:
            print(self.default_path)
        return result


def win_close(xvar):
    xvar.mlx.mlx_loop_exit(xvar.mlx_ptr)


def input_validator(height, width, entry, exit):
    if width <= 8:
        width = 9
    if height <= 6:
        height = 7
    if exit[0] >= width:
        exit[0] = entry[0]+1
    if exit[1] >= height:
        exit[1] = entry[1]+1
    return [height, width, entry, exit]


if __name__ == "__main__":
    seeded = False
    xvar = XVar()
    try:
        with open(sys.argv[1]) as f:
            for line in f:
                name, value = line.split("=")
                if name == "WIDTH":
                    width = int(value)
                if name == "HEIGHT":
                    height = int(value)
                if name == "ENTRY":
                    x, y = value.split(",")
                    entry = [int(x), int(y)]
                if name == "EXIT":
                    x, y = value.split(",")
                    exit = [int(x), int(y)]
                if name == "OUTPUT_FILE":
                    output_file = str(value).removesuffix("\n")
                if name == "PERFECT":
                    bool_map = {"true": True, "false": False}
                    perfect = bool_map.get(value.strip().lower(), False)
                if name == "SEED":
                    seeded = True
                    seed = str(value)
            if seeded is True:
                print("=== Seeded mode ===")
                try:
                    [
                        width, height, entry, exit, path, maze
                    ] = reverse_bit_math(seed)
                except Exception as e:
                    print("Seed mode error: ", e)
                    # exit(1)  # should this be here? i dont think so
                block_size = int(xvar.block_size_math(height, width))
                xvar.set_default_info(
                    width, height, block_size, entry, exit, perfect
                )
                lol = MazeGenerator(
                    width * height, width, height, block_size,
                    entry, exit, perfect, seed, path, maze
                )
            elif seeded is False:
                print("=== Random mode ===")
                [
                    height, width, entry, exit
                ] = input_validator(height, width, entry, exit)
                block_size = int(xvar.block_size_math(height, width))
                xvar.set_default_info(
                    width,
                    height,
                    block_size,  # block_size,
                    entry,
                    exit,
                    perfect
                )
                lol = MazeGenerator(
                    width * height, width, height, block_size, entry, exit,
                    perfect=perfect
                )
                lol.maze_carver(entry[0], entry[1])
    except Exception as e:
        print(f"Some error happened on: {e}\n\
Generating random maze with default values...\n")
        width = 30
        height = 30
        entry = [0, 0]
        exit = [width - 1, height - 1]
        output_file = "maze.txt"
        perfect = True
        block_size = int(xvar.block_size_math(height, width))
        lol = MazeGenerator(
            width * height, width, height, block_size, entry, exit,
            perfect=perfect
        )
        lol.maze_carver(entry[0], entry[1])

    # Mlx Initialisation
    try:
        xvar.mlx = Mlx()
    except Exception as e:
        print(f"Error: Can't initialize MLX: {e}", file=sys.stderr)
        sys.exit(1)
    xvar.mlx_ptr = xvar.mlx.mlx_init()

    ret, xvar.screen_w, xvar.screen_h = xvar.mlx.mlx_get_screen_size(
        xvar.mlx_ptr
    )

    # Windows creation
    try:
        xvar.win = xvar.mlx.mlx_new_window(
            xvar.mlx_ptr,
            block_size*width,
            block_size*height + 40,
            "MLX main win"
        )  # infer size from HEIGHT and WIDTH | THE EXTRA height is for options
        if not xvar.win:
            raise Exception("Can't create main window")
    except Exception as e:
        print(f"Error Win create: {e}", file=sys.stderr)
        sys.exit(1)

    xvar.set_maze(lol)

    mlx = Mlx()
    mlx.mlx_init()
    with open(output_file, "w") as out_file:
        out_file.write(lol.printMaze())
        out_file.write(lol.print_default_path(True))
        print("saved to file")
    lol.printMlx(xvar)
    # solved = Solver(lol.get_maze())
    # solved.solve(ENTRY, EXIT)
    # ^these do not work, if we implement some other solver\
    # it will probably work like this tho

    xvar.mlx.mlx_key_hook(xvar.win, gere_key, xvar)
    xvar.mlx.mlx_hook(xvar.win, 33, 0, win_close, xvar)
    xvar.mlx.mlx_loop(xvar.mlx_ptr)

    # Cleaning resources
    xvar.mlx.mlx_destroy_window(xvar.mlx_ptr, xvar.win)
    xvar.mlx.mlx_release(xvar.mlx_ptr)


# TODO
# Optional: set specific colours to display the “42” pattern.
# ^literally free, just a matter of splitting the pallet of the 42

# TODO Xtone special
# line solution
# ^i am quite unsure how i would go about this, maybe just offset a wedge...

# TODO BONUS
# Support multiple maze generation algorithms
# ^simple enough

# Add animation during maze generation
# ^split the printing maze from printing the solution, then stagger the\
# solution

# TODO EXTRA
# README.md
