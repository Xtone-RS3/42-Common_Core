from ex0.Card import Card


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        self.name = name
        self.cost = cost
        self.rarity = rarity
        self.effect_type = effect_type

    def play(self, game_state: dict) -> dict:
        if self.effect_type == "damage" or self.effect_type == "heal":
            return {"card_played": self.name, "mana_used": self.cost, "effect": f"{self.cost} {self.effect_type} to target"}  # noqa: E501
        elif self.effect_type == "buff" or self.effect_type == "debuff":
            return {"card_played": self.name, "mana_used": self.cost, "effect": f"{self.effect_type} target"}  # noqa: E501

    def resolve_effect(self, targets: list) -> dict:
        pass
