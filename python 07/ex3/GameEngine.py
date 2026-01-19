import random
from .CardFactory import CardFactory
from .GameStrategy import GameStrategy
from ex0.CreatureCard import CreatureCard


class GameEngine:
    def __init__(self, deck: list):
        self.deck = deck
        self.hand = []
        self.battlefield = []
        self.turn = 0
        self.strat: GameStrategy = None
        self.factory: CardFactory = None

    def configure_engine(self, factory: CardFactory, strategy: GameStrategy) -> None:  # noqa: E501
        """draw 3 cards from deck to hand"""
        self.strat = strategy
        self.factory = factory
        for _ in range(3):
            card = random.choice(self.deck)
            self.hand.append(card)
            self.deck.remove(card)

    def simulate_turn(self) -> dict:
        """draw 1 card from deck to hand, then simulate"""
        self.turn += 1
        card = random.choice(self.deck)
        self.hand.append(card)
        self.deck.remove(card)
        return self.strat.execute_turn(self.hand, [CreatureCard("Enemy", 1, "common", 3, 20)])  # noqa: E501

    def get_engine_status(self) -> dict:
        return {'turns_simulated': self.turn, 'strategy_used': self.strat.get_strategy_name(), 'total_damage': self.strat.damage_dealt, 'cards_created': self.factory.cards_created}  # noqa: E501
