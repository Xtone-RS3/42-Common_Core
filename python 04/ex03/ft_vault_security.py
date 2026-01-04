def archiver(f):
    try:
        print("SECURE PRESERVATION:")
        with open("security_protocols.txt", 'w') as f2:
            f2.write("[CLASSIFIED] New security protocols archived")
            print("[CLASSIFIED] New security protocols archived")
    except PermissionError:
        print("ERROR: File permission denied!")
    print("Vault automatically sealed upon completion")


def secure_access():
    try:
        print("Initiating secure vault access...")
        with open("classified_data.txt") as f1:
            print("Vault connection established with failsafe protocols")
            print()
            print(f1.read())
            print()
            archiver(f1)
    except PermissionError:
        print("ERROR: File permission denied!")
    print()
    print("All vault operations completed with maximum security.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    print()
    secure_access()
