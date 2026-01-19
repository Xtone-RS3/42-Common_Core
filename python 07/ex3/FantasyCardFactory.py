from ex0.Card import Card
from .CardFactory import CardFactory
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard
from ex0.CreatureCard import CreatureCard
import random


class FantasyCardFactory(CardFactory):
    def create_creature(self, name_or_power: str | int | None = None) -> Card:
        self.cards_created += 1
        return CreatureCard(name_or_power, random.randint(1, 10), random.choice(["common", "uncommon", "rare", "legendary"]), random.randint(1, 10), random.randint(1, 10))  # noqa: E501

    def create_spell(self, name_or_power: str | int | None = None) -> Card:
        self.cards_created += 1
        return SpellCard(name_or_power, random.randint(1, 10), random.choice(["common", "uncommon", "rare", "legendary"]), random.choice(["damage", "heal", "buff", "debuff"]))  # noqa: E501

    def create_artifact(self, name_or_power: str | int | None = None) -> Card:
        self.cards_created += 1
        return ArtifactCard(name_or_power, random.randint(1, 10), random.choice(["common", "uncommon", "rare", "legendary"]), random.randint(1, 5), "lol, lmao even")  # noqa: E501

    def create_themed_deck(self, size: int) -> dict:
        types: dict = self.get_supported_types()
        keys: list[str] = list(types.keys())
        for _ in range(size):
            card_type = random.choice(keys)
            card_name = random.choice(types[card_type])
            if card_type == "creatures":
                card = self.create_creature(card_name)
            elif card_type == "spells":
                card = self.create_spell(card_name)
            elif card_type == "artifacts":
                card = self.create_artifact(card_name)
            self.deck.append(card)
        return self.deck

    def get_supported_types(self) -> dict:
        result = {
            "creatures": ["Mind Goblin", "Fire Dragon", "Giant Enemy Crab"],
            "spells": ["Lightning bolt", "Volt tackle", "Earthquake", "Ligma"],
            "artifacts": ["DN", "Mana Ring"]
        }
        return result
