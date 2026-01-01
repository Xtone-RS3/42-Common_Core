def garden_operations():
    arr = {"a": 1}
    try:
        print("Testing ValueError...")
        int("lmao")
    except ValueError:
        print("Caught ValueError: invalid literal for int()")
    print()
    try:
        print("Testing ZeroDivisionError...")
        int(5/0)
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
    print()
    try:
        print("Testing FileNotFoundError...")
        open("missing.txt", 'r')
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'")
    print()
    try:
        print("Testing KeyError...")
        print(arr["b"])
    except KeyError:
        print("Caught KeyError: 'missing\_plant'")
    print()
    try:
        print("Testing multiple errors together...")
        int("lmao")
        int(5/0)
        open("missing.txt", 'r')
        print(arr["b"])
    except (ValueError, ZeroDivisionError, FileNotFoundError, KeyError):
        print("Caught an error, but program continues!")
    print()
    print("All error types tested successfully")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    print()
    garden_operations()
