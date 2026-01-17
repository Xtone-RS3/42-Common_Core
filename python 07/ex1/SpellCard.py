from ex0.Card import Card


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        self.name = name
        self.cost = cost
        self.rarity = rarity
        self.effect_type = effect_type

    def play(self, game_state: dict) -> dict:
        if self.effect_type == "damage":
            pass
        elif self.effect_type == "heal":
            pass
        elif self.effect_type == "buff":
            pass
        elif self.effect_type == "debuff":
            pass

    def resolve_effect(self, targets: list) -> dict:
        pass
