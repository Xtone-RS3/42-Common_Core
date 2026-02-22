from .FantasyCardFactory import FantasyCardFactory
from .AggressiveStrategy import AggressiveGameStrategy
from ex1.Deck import Deck
from .GameEngine import GameEngine

if __name__ == "__main__":
    print("=== DataDeck Game Engine ===")
    print()
    print("Configuring Fantasy Card Game...")
    my_deck = Deck()
    factory = FantasyCardFactory()
    strategy = AggressiveGameStrategy()
    engine = GameEngine(factory.create_themed_deck(5))
    print(
        "Factory:",
        type(factory).__name__
    )
    print(
        "Strategy:",
        type(strategy).__name__
    )
    print(
        "Available types:",
        factory.get_supported_types()
    )
    engine.configure_engine(factory, strategy)
    print()
    print("Simulating aggressive turn...")
    print("Hand: ", end="")
    for card in engine.hand:
        print(
            card.name,
            f"({card.cost})", end=", "
        )
    print("\n")
    print("Turn execution:")
    print(
        "Strategy:",
        strategy.get_strategy_name()
    )
    print(
        "Actions:",
        engine.simulate_turn()
    )
    print()
    print(
        "Game report:",
        engine.get_engine_status()
    )
    print()
    print("Abstract Factory + Strategy Pattern: Maximum flexibility achieved!")
