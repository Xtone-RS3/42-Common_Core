import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    if len(sys.argv) == 1:
        print("No arguments provided!")
    print(f"Program name: {sys.argv[0]}")
    x = 1
    for arg in sys.argv[1:]:
        print(f"Argument {x}: {arg}")
        x += 1
    print(f"Total arguments: {len(sys.argv)}")
