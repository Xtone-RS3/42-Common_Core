def lost_func():
    print("CRISIS ALERT: Attempting access to 'lost_archive.txt'...")
    try:
        with open("lost_archive.txt") as f:
            print("SUCCESS: Displaying contents...")
            f.read()
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
    print("STATUS: Crisis handled, system stable")


def perms_func():
    try:
        with open("classified_vault.txt") as f:
            print("SUCCESS: Displaying contents...")
            f.read()
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
    print("STATUS: Crisis handled, security maintained")


def routine_func():
    print("ROUTINE ACCESS: Attempting access to 'standard_archive.txt'...")
    try:
        with open("standard_archive.txt") as f:
            print(f"SUCCESS: Archive recovered - '{f.read()}'")
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
    print("STATUS: Normal operations resumed")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    print()
    lost_func()
    print()
    perms_func()
    print()
    routine_func()
    print()
    print("All crisis scenarios handled successfully. Archives secure.")
