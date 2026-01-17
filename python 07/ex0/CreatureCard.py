from .Card import Card


class CreatureCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, attack: int, health: int):  # noqa: E501
        self.name = name
        self.cost = cost
        self.rarity = rarity
        self.attack = attack
        self.health = health

    def play(self, game_state: dict) -> dict:
        return {"card played": self.name, "mana_used": self.cost, "effect": "Creature summoned to battlefield"}  # noqa: E501

    def attack_target(self, target) -> dict:
        return {"attacker": self.name, "target": target, "damage_dealt": self.attack, "combat_resolved": True}  # noqa: E501

    def get_card_info(self) -> dict:
        return {"name": self.name, "cost": self.cost, "rarity": self.rarity, "type": "Creature", "attack": self.attack, "health": self.health}  # noqa: E501
