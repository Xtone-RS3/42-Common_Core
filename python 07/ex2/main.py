from ex0.Card import Card  # noqa: F401
from .EliteCard import EliteCard


if __name__ == "__main__":
    cracked_card = EliteCard("Mind Goblin", 3, "Legendary", 10, 5)
    print("=== DataDeck Ability System ===")
    print()
    print(
        "EliteCard capabilities:",
        "- Card: ['play', 'get_card_info', 'is_playable']",
        "- Combatable: ['attack', 'defend', 'get_combat_stats']",
        "- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']"
    )
    print()
    print(f"Playing {cracked_card.name} (Elite Card):")
    print()
    print(
        "Attack result:",
        cracked_card.attack("DN")
    )
    print(
        "Defense result:",
        cracked_card.defend(8)
    )
    print()
    print("Magic phase:")
    print(
        "Spell cast:",
        cracked_card.cast_spell("Thunderbolt", ["Sonichu", "Giant Enemy Crab"])
    )
    print(
        "Mana channel:",
        cracked_card.channel_mana(6)
    )
    print()
    print("Multiple interface implementation successful!")
