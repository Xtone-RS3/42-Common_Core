import sys
import math

if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    if len(sys.argv) == 2:
        point = tuple(sys.argv[1].split(sep=","))
    elif len(sys.argv) == 4:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
        z = int(sys.argv[3])
        print(f"Position created: ({x}, {y}, {z})")
        point = tuple(sys.argv[1:])
        dist = math.sqrt((0-x)**2 + (0-y)**2 + (0-z)**2)
        print(f"Distance between (0, 0, 0) and ({x}, {y}, {z}): {dist:.2f}")
    else:
        print("Error: Invalid coordinates")
