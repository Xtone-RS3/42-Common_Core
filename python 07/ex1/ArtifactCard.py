from ex0.Card import Card


class ArtifactCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, durability: int, effect: str):  # noqa: E501
        self.name = name
        self.cost = cost
        self.rarity = rarity
        self.durability = durability
        self.effect = effect

    def play(self, game_state: dict) -> dict:
        return {"card_played": self.name, "mana_used": self.cost, "effect": self.effect}  # noqa: E501

    def activate_ability(self) -> dict:
        pass
