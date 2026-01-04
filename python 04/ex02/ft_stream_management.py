import sys


def comms():
    id = input("Input Stream active. Enter archivist ID: ")
    status = input("Input Stream active. Enter status report: ")
    print()
    print(f"[STANDARD] Archive status from {id}: {status}")
    sys.stderr.write("[ALERT] System diagnostic: Communication channels\
 verified\n")
    sys.stdout.write("[STANDARD] Data transmission complete\n")
    print()
    print("Three-channel communication test successful.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    print()
    comms()
