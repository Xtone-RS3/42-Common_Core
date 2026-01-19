from .TournamentPlatform import TournamentPlatform
from .TournamentCard import TournamentCard


if __name__ == "__main__":
    print("=== DataDeck Tournament Platform ===")
    print()
    print("Registering Tournament Cards...")
    print()
    tourn = TournamentPlatform()
    dragon_001 = TournamentCard("Fire Dragon", 5, "common", 10, 5)
    tourn.register_card(dragon_001)
    print(
        dragon_001.name,
        "(ID: dragon_001):"
    )
    print(
        "- Interfaces:",
        [classy.__name__ for classy in type(dragon_001).__mro__ if classy.__name__ not in ["TournamentCard", "ABC", "object"]]
    )
    print(
        "- Rating:",
        dragon_001.rating
    )
    print(
        "- Record:",
        f"{dragon_001.wins}-{dragon_001.losses}"
    )
    print()
    wizard_001 = TournamentCard("Time Wizard", 6, "common", 5, 10)
    tourn.register_card(wizard_001)
    print(
        wizard_001.name,
        "(ID: wizard_001):"
    )
    print(
        "- Interfaces:",
        [classy.__name__ for classy in type(wizard_001).__mro__ if classy.__name__ not in ["TournamentCard", "ABC", "object"]]
    )
    print(
        "- Rating:",
        wizard_001.rating
    )
    print(
        "- Record:",
        f"{wizard_001.wins}-{wizard_001.losses}"
    )
    print()
    print("Creating tournament match...")
    print(
        "Match result:",
        tourn.create_match(dragon_001.name, wizard_001.name)
    )
