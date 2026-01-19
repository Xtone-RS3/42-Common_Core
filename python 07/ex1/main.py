from ex0.Card import Card  # noqa: F401
from ex0.CreatureCard import CreatureCard
from .ArtifactCard import ArtifactCard
from .SpellCard import SpellCard
from .Deck import Deck


if __name__ == "__main__":
    print("=== DataDeck Deck Builder ===")
    print()
    print("Building deck with different card types...")
    fire_dragon = CreatureCard('Fire Dragon', 5, "Legendary", 7, 5)
    lightning_bolt = SpellCard("Lightning Bolt", 3, "common", "damage")
    mana_crystal = ArtifactCard("Mana Crystal", 2, "common", 5, "Permanent: +1 mana per turn")  # noqa: E501
    mind_goblind = CreatureCard("Mind Goblin", 1, "Mythic", 999, 999)
    my_deck = Deck()
    my_deck.add_card(fire_dragon)
    my_deck.add_card(lightning_bolt)
    my_deck.add_card(mana_crystal)
    # my_deck.add_card(mind_goblind)
    print(
        "Deck stats:",
        my_deck.get_deck_stats()
    )
    print()
    print("Drawing and playing cards:")
    print()
    draw_one = my_deck.draw_card()
    print(
        "Drew:",
        draw_one.name,
        "-",
        type(draw_one).__name__
    )
    print(
        "Play result:",
        draw_one.play(None)
    )
    my_deck.remove_card(draw_one.name)
    print()
    draw_two = my_deck.draw_card()
    print(
        "Drew:",
        draw_two.name,
        "-",
        type(draw_two).__name__
    )
    print(
        "Play result:",
        draw_two.play(None)
    )
    my_deck.remove_card(draw_two.name)
    print()
    draw_three = my_deck.draw_card()
    print(
        "Drew:",
        draw_three.name,
        "-",
        type(draw_three).__name__
    )
    print(
        "Play result:",
        draw_three.play(None)
    )
    my_deck.remove_card(draw_three.name)
    print()
    # print(
    #    "Deck stats:",
    #    my_deck.get_deck_stats()
    # )
    print("Polymorphism in action: Same interface, different card behaviors!")
