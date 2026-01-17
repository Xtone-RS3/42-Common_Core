from .CreatureCard import CreatureCard


if __name__ == "__main__":
    print("=== DataDeck Card Foundation ===")
    print()
    print("Testing Abstract Base Class Design:")
    print()
    print("CreatureCard Info:")
    fire_dragon = CreatureCard('Fire Dragon', 5, "Legendary", 7, 5)
    mind_goblind = CreatureCard("Mind Goblin", 1, "Mythic", 999, 999)
    goblin_warrior = CreatureCard("Goblin Warrior", 2, "Common", 2, 1)
    print(fire_dragon.get_card_info())
    print()
    print("Playing Fire Dragon with 6 mana available:")
    play_this = fire_dragon.is_playable(6)
    print("Playable:", play_this)
    if play_this:
        print("Play result:", fire_dragon.play(None))
    print()
    print("Fire Dragon attacks Goblin Warrior:")
    print(
        "Attack result:",
        fire_dragon.attack_target(goblin_warrior.name)
    )
    print()
    print("Testing insufficient mana (3 available):")
    play_that = fire_dragon.is_playable(3)
    print("Playable:", play_that)
    if play_that:
        print("Play result:", fire_dragon.play(None))
    print()
    print("Abstract pattern successfully demonstrated!")
