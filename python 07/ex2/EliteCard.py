from ex0.Card import Card
from .Magical import Magical
from .Combatable import Combatable


class EliteCard(Card, Magical, Combatable):
    def __init__(self, name, cost, rarity, attack_stat, block):
        super().__init__(name, cost, rarity)
        self.attack_stat = attack_stat
        self.block = block

    def play(self, game_state: dict) -> dict:
        pass

    def attack(self, target) -> dict:
        """combat attack"""
        return {'attacker': self.name, 'target': target, 'damage': self.attack_stat, 'combat_type': 'melee'}  # noqa: E501

    def defend(self, incoming_damage: int) -> dict:
        """combat defend"""
        taken = incoming_damage - self.block
        if taken < 0:
            taken = 0
        return {'defender': self.name, 'damage_taken': taken, 'damage_blocked': self.block, 'still_alive': True}  # noqa: E501

    def get_combat_stats(self) -> dict:
        """combat stats"""
        pass

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        """magic attack"""
        return {'caster': self.name, 'spell': spell_name, 'targets': targets, 'mana_used': self.cost}  # noqa: E501

    def channel_mana(self, amount: int) -> dict:
        """magic something-or-other"""
        return {'channeled': amount, 'total_mana': 7}

    def get_magic_stats(self) -> dict:
        """magic stats"""
        pass
