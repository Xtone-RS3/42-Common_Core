from ex0.Card import Card
from ex2.Combatable import Combatable
from .Rankable import Rankable


class TournamentCard(Card, Combatable, Rankable):
    def __init__(self, name, cost, rarity, attack_stat, block):
        super().__init__(name, cost, rarity)
        self.wins = 0
        self.losses = 0
        self.rating = 0
        self.attack_stat = attack_stat
        self.block = block

    def calculate_rating(self) -> int:
        pass

    def update_wins(self, wins: int) -> None:
        self.wins = wins
        return self.wins

    def update_losses(self, losses: int) -> None:
        self.losses = losses
        return self.losses

    def get_rank_info(self) -> dict:
        pass

    def attack(self, target) -> dict:
        pass

    def defend(self, incoming_damage: int) -> dict:
        pass

    def get_combat_stats(self) -> dict:
        pass

    def play(self, game_state: dict) -> dict:
        pass

    def get_tournament_stats(self) -> dict:
        pass
