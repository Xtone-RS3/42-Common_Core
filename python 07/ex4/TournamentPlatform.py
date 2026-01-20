from .TournamentCard import TournamentCard
import random


class TournamentPlatform:
    def __init__(self):
        self.cards: dict[str: TournamentCard] = {}
        self.matches = 0
        self.total_cards = 0

    def register_card(self, card: TournamentCard) -> str:
        self.total_cards += 1
        number = 1
        for card_lol in self.cards:
            if card_lol.startswith(card.name.split()[1].lower()):
                number += 1
        card_id = card.name.split()[1].lower() + f"_{number:03}"
        self.cards[card_id] = card
        return card_id

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        self.matches += 1
        players = [card1_id, card2_id]
        random.shuffle(players)
        elo_change = abs(self.cards[card1_id].rating - self.cards[card2_id].rating) / 3  # noqa: E501
        if elo_change == 0:
            elo_change = 1
        self.cards[players[0]].wins += 1
        self.cards[players[1]].losses += 1
        self.cards[players[0]].rating += elo_change
        self.cards[players[1]].rating -= elo_change
        return {'winner': players[0], 'loser': players[1], 'winner_rating': int(self.cards[players[0]].rating), 'loser_rating': int(self.cards[players[1]].rating)}  # noqa: E501

    def get_leaderboard(self) -> list:
        cards: list[TournamentCard] = [
            self.cards[id] for id in self.cards.keys()
        ]
        return sorted(
            cards, key=lambda card: card.rating,
            reverse=True
        )

    def generate_tournament_report(self) -> dict:
        total_elo = 0
        for card in self.cards:
            total_elo += self.cards[card].rating
        return {
            'total_cards': self.total_cards,
            'matches_played': self.matches,
            'avg_rating': int(total_elo / self.total_cards),
            'platform_status': 'active'
        }
