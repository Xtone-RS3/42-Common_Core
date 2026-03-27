*This project has been created as part of the 42 curriculum by gasoares.*

# Drone Pathfinding with Time-Expanded A* and Reservations

## Description

This project implements a **multi-drone pathfinding system** using a modified **A\* (A-star) algorithm** in a constrained environment.

The goal is to compute collision-free paths for multiple drones navigating through a graph of interconnected cells while respecting:
- Node capacity constraints (maximum drones per cell)
- Edge capacity constraints (maximum drones per connection)
- Special zone behaviors (restricted, priority, etc.)
- Time-based reservations to prevent conflicts

Each drone is routed sequentially, and previously computed paths are stored in a **reservation system** to ensure no overlaps occur in space-time.

### Key Features
- Time-expanded A* pathfinding
- Collision avoidance via reservation tables
- Support for different zone types:
  - `normal`
  - `restricted` (extra traversal cost and delay)
  - `priority` (reduced traversal cost)
  - `blocked`
- Capacity-constrained nodes and edges
- Two visualization modes:
  - Step-by-step path per drone
  - Turn-by-turn simulation output

---

## Instructions

### Requirements
- Python 3.x

### Compilation / Execution

No compilation is required.

Run the program with:

- make run MAP=<map_file.txt>

---

## Resources

### References

- A* algo
  - https://en.wikipedia.org/wiki/A*_search_algorithm
  - https://www.geeksforgeeks.org/python/a-search-algorithm-in-python/

- Multi agent
  - https://en.wikipedia.org/wiki/Multi-agent_pathfinding

