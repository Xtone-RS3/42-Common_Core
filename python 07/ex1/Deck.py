from ex0.Card import Card
import random


class Deck(object):
    def __init__(self):
        self.deck = []

    def add_card(self, card: Card) -> None:
        if card not in self.deck:
            self.deck.append(card)

    def remove_card(self, card_name: str) -> bool:
        for card in self.deck:
            if card_name == card.name:
                self.deck.remove(card)

    def shuffle(self) -> None:
        random.shuffle(self.deck)

    def draw_card(self) -> Card:
        return (random.choice(self.deck))

    def get_deck_stats(self) -> dict:
        spell = 0
        artifact = 0
        creature = 0
        total_cost = 0
        for card in self.deck:
            if type(card).__name__ == "CreatureCard":
                creature += 1
            elif type(card).__name__ == "SpellCard":
                spell += 1
            elif type(card).__name__ == "ArtifactCard":
                artifact += 1
            total_cost += card.cost
        if (creature + spell + artifact) == 0:
            return {"total_cards": len(self.deck), "creatures": creature, "spells": spell, "artifacts": artifact, "avg_cost": "lol"}  # noqa: E501
        return {"total_cards": len(self.deck), "creatures": creature, "spells": spell, "artifacts": artifact, "avg_cost": total_cost / (creature + spell + artifact)}  # noqa: E501
