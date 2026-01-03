import sys
import math

if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    if len(sys.argv) == 2:
        try:
            point = tuple(int(x) for x in sys.argv[1].split(sep=","))
        except ValueError:
            print(f"Error parsing coordinates: invalid literal for int() with\
 base 10: '{sys.argv[1]}'")
            sys.exit(0)
    elif len(sys.argv) == 4:
        try:
            point = tuple(int(x) for x in sys.argv[1:])
        except ValueError:
            print(f"Error parsing coordinates: invalid literal for int() with\
 base 10: '{sys.argv[1]}'")
            sys.exit(0)
    else:
        print("Error: Invalid coordinates")
        sys.exit(0)
    print(f"Position created: ({point[0]}, {point[1]}, {point[2]})")
    dist = math.sqrt((0-point[0])**2 + (0-point[1])**2 + (0-point[2])**2)
    print(f"Distance between (0, 0, 0) and ({point[0]}, {point[1]},\
 {point[2]}): {dist:.2f}")
