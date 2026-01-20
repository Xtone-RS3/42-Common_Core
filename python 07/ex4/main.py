from .TournamentPlatform import TournamentPlatform
from .TournamentCard import TournamentCard


if __name__ == "__main__":
    print("=== DataDeck Tournament Platform ===")
    print()
    print("Registering Tournament Cards...")
    print()
    tourn = TournamentPlatform()
    dragon_001 = TournamentCard("Fire Dragon", 5, "common", 10, 5)
    print(
        dragon_001.name,
        f"(ID: {tourn.register_card(dragon_001)}):"
    )
    print(
        "- Interfaces:",
        [classy.__name__ for classy in type(dragon_001).__mro__ if classy.__name__ not in ["TournamentCard", "ABC", "object"]]  # noqa: E501
    )
    print(
        "- Rating:",
        dragon_001.calculate_rating()
    )
    print(
        "- Record:",
        f"{dragon_001.wins}-{dragon_001.losses}"
    )
    print()
    wizard_001 = TournamentCard("Time Wizard", 6, "common", 5, 10)
    print(
        wizard_001.name,
        f"(ID: {tourn.register_card(wizard_001)}):"
    )
    print(
        "- Interfaces:",
        [classy.__name__ for classy in type(wizard_001).__mro__ if classy.__name__ not in ["TournamentCard", "ABC", "object"]]  # noqa: E501
    )
    print(
        "- Rating:",
        wizard_001.calculate_rating()
    )
    print(
        "- Record:",
        f"{wizard_001.wins}-{wizard_001.losses}"
    )
    print()
    print("Creating tournament match...")
    print(
        "Match result:",
        tourn.create_match("dragon_001", "wizard_001")
    )
    print()
    print("Tournament Leaderboard:")
    n = 0
    for card in tourn.get_leaderboard():
        n += 1
        print(
            f"{n}.",
            f"{card.name} -",
            f"Rating: {int(card.rating)}",
            f"{card.wins}-{card.losses}"
        )
    print()
    print("Platform Report:")
    print(tourn.generate_tournament_report())
    print()
    print("=== Tournament Platform Successfully Deployed! ===")
    print("All abstract patterns working together harmoniously!")
