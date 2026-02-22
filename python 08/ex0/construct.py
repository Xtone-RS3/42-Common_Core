import sys
import os


def in_venv():
    return sys.prefix != sys.base_prefix


if __name__ == "__main__":
    print(
        "MATRIX STATUS:"
    )
    print()
    if in_venv():
        print(
            "Current Python:",
            sys.executable
        )
        print("Virtual Environment: ", end="")
        print(os.path.basename(sys.prefix))
        print(
            "Environment Path:",
            sys.prefix
        )
        print()
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting the global system.")
        print()
        print("Package installation path:")
        print(sys.path[4])
    else:
        print(
            "Current Python:",
            sys.executable
        )
        print("Virtual Environment: ", end="")
        print("None detected")
        print()
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.")
        print()
        print("To enter the construct, run:")
        print("python3 -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env")
        print("Scripts")
        print("activate # On Windows")
        print()
        print("Then run this program again.")
