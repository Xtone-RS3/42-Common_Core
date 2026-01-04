def preservation_sys():
    try:
        print("Initializing new storage unit: new_discovery.txt")
        with open("new_discovery.txt", "w") as f:
            print("Storage unit created successfully...")
            print()
            print("Inscribing preservation data...")
            f.write("[ENTRY 001] New quantum algorithm discovered\n")
            print("[ENTRY 001] New quantum algorithm discovered")
            f.write("[ENTRY 002] Efficiency increased by 347%\n")
            print("[ENTRY 002] Efficiency increased by 347%")
            f.write("[ENTRY 003] Archived by Data Archivist trainee\n")
            print("[ENTRY 003] Archived by Data Archivist trainee")
            print()
            f.close()
            print("Data inscription complete. Storage unit sealed")
            print("Archive 'new_discovery.txt' ready for long-term\
 preservation.")
    except PermissionError:
        print("ERROR: File permission denied!")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print()
    preservation_sys()
