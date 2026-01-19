from .GameStrategy import GameStrategy
from ex0.Card import Card
from ex1.ArtifactCard import ArtifactCard  # noqa: F401
from ex0.CreatureCard import CreatureCard  # noqa: F401
from ex1.SpellCard import SpellCard  # noqa: F401


class AggressiveGameStrategy(GameStrategy):
    def execute_turn(self, hand: list[Card], battlefield: list) -> dict:
        mana = 10
        cards_played = []
        for card in hand:
            if card.is_playable(mana):
                card.play(None)
                mana -= card.cost
                cards_played.append(card.name)
                if type(card).__name__ == "CreatureCard":
                    self.damage_dealt += card.attack
                    card.attack_target(battlefield)
        return {
            'cards_played': cards_played,
            'mana_used': 10 - mana,
            'targets_attacked': [enemy.name for enemy in battlefield],
            'damage_dealt': self.damage_dealt
        }

    def get_strategy_name(self) -> str:
        return type(self).__name__

    def prioritize_targets(self, available_targets: list) -> list:
        valid_targets = [
            target for target in available_targets
            if available_targets[target].health > 0
        ]
        return valid_targets  # sorted(valid_targets)
