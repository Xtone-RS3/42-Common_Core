if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    alice = set(["first_kill", "level_10", "treasure_hunter", "speed_demon"])
    print(f"Player alice achievements: {alice}")
    bob = set(["first_kill", "level_10", "boss_slayer", "collector"])
    print(f"Player bob achievements: {bob}")
    charlie = set(["level_10", "treasure_hunter", "boss_slayer", "speed_demon",
                   "perfectionist"])
    print(f"Player charlie achievements: {charlie}")
    print()

    print("=== Achievement Analytics ===")
    total = alice | bob | charlie
    print(f"All unique achievements: {total}")
    print(f"Total unique achievements: {len(total)}")
    print()
    print(f"Common to all players: {alice & bob & charlie}")
    print(f"Rare achievements (1 player):\
{total - ((alice & bob) | (alice & charlie) | (bob & charlie))}")
    print()
    print(f"Alice vs Bob common: {(alice & bob)}")
    print(f"Alice unique: {(alice - bob)}")
    print(f"Alice ACTUALLY unique: {(alice - (bob | charlie))}")
    print(f"Bob unique: {bob - alice}")
    print(f"Bob ACTUALLY unique: {(bob - (alice | charlie))}")
