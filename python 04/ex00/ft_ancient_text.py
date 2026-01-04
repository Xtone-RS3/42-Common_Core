def data_recovery():
    try:
        print("Accessing Storage Vault: ancient\\_fragment.txt")
        with open("ancient_fragment.txt") as f:
            print("Connection established...")
            print()
            print("RECOVERED DATA:")
            print(f.read())
            print()
            f.close()
            print("Data recovery complete. Storage unit disconnected.")
    except FileNotFoundError:
        print("ERROR: Storage vault not found. Run data generator first.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print()
    data_recovery()
