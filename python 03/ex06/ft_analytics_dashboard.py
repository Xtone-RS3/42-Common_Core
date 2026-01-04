if __name__ == "__main__":
    print("=== Game Analytics Dashboard ===")
    everything = {
     'players': {
         'alice': {
             'level': 41,
             'total_score': 2824,
             'sessions_played': 13,
             'favorite_mode': 'ranked',
             'achievements_count': 5
         },
         'bob': {
             'level': 16,
             'total_score': 4657,
             'sessions_played': 27,
             'favorite_mode': 'ranked',
             'achievements_count': 2
         },
         'charlie': {
             'level': 44,
             'total_score': 9935,
             'sessions_played': 21,
             'favorite_mode': 'ranked',
             'achievements_count': 7
         },
         'diana': {
             'level': 3,
             'total_score': 1488,
             'sessions_played': 21,
             'favorite_mode': 'casual',
             'achievements_count': 4
         },
         'eve': {
             'level': 33,
             'total_score': 1434,
             'sessions_played': 81,
             'favorite_mode': 'casual',
             'achievements_count': 7
         },
         'frank': {
             'level': 15,
             'total_score': 8359,
             'sessions_played': 85,
             'favorite_mode': 'competitive',
             'achievements_count': 1
         }
     },
     'sessions': [
         {'player': 'bob', 'duration_minutes': 94,
          'score': 1831, 'mode': 'competitive', 'completed': False},
         {'player': 'bob', 'duration_minutes': 32,
          'score': 1478, 'mode': 'casual', 'completed': True},
         {'player': 'diana', 'duration_minutes': 17,
          'score': 1570, 'mode': 'competitive', 'completed': False},
         {'player': 'alice', 'duration_minutes': 98,
          'score': 1981, 'mode': 'ranked', 'completed': True},
         {'player': 'diana', 'duration_minutes': 15,
          'score': 2361, 'mode': 'competitive', 'completed': False},
         {'player': 'eve', 'duration_minutes': 29,
          'score': 2985, 'mode': 'casual', 'completed': True},
         {'player': 'frank', 'duration_minutes': 34,
          'score': 1285, 'mode': 'casual', 'completed': True},
         {'player': 'alice', 'duration_minutes': 53,
          'score': 1238, 'mode': 'competitive', 'completed': False},
         {'player': 'bob', 'duration_minutes': 52,
          'score': 1555, 'mode': 'casual', 'completed': False},
         {'player': 'frank', 'duration_minutes': 92,
          'score': 2754, 'mode': 'casual', 'completed': True},
         {'player': 'eve', 'duration_minutes': 98,
          'score': 1102, 'mode': 'casual', 'completed': False},
         {'player': 'diana', 'duration_minutes': 39,
          'score': 2721, 'mode': 'ranked', 'completed': True},
         {'player': 'frank', 'duration_minutes': 46,
          'score': 329, 'mode': 'casual', 'completed': True},
         {'player': 'charlie', 'duration_minutes': 56,
          'score': 1196, 'mode': 'casual', 'completed': True},
         {'player': 'eve', 'duration_minutes': 117,
          'score': 1388, 'mode': 'casual', 'completed': False},
         {'player': 'diana', 'duration_minutes': 118,
          'score': 2733, 'mode': 'competitive', 'completed': True},
         {'player': 'charlie', 'duration_minutes': 22,
          'score': 1110, 'mode': 'ranked', 'completed': False},
         {'player': 'frank', 'duration_minutes': 79,
          'score': 1854, 'mode': 'ranked', 'completed': False},
         {'player': 'charlie', 'duration_minutes': 33,
          'score': 666, 'mode': 'ranked', 'completed': False},
         {'player': 'alice', 'duration_minutes': 101,
          'score': 292, 'mode': 'casual', 'completed': True},
         {'player': 'frank', 'duration_minutes': 25,
          'score': 2887, 'mode': 'competitive', 'completed': True},
         {'player': 'diana', 'duration_minutes': 53,
          'score': 2540, 'mode': 'competitive', 'completed': False},
         {'player': 'eve', 'duration_minutes': 115,
          'score': 147, 'mode': 'ranked', 'completed': True},
         {'player': 'frank', 'duration_minutes': 118,
          'score': 2299, 'mode': 'competitive', 'completed': False},
         {'player': 'alice', 'duration_minutes': 42,
          'score': 1880, 'mode': 'casual', 'completed': False},
         {'player': 'alice', 'duration_minutes': 97,
          'score': 1178, 'mode': 'ranked', 'completed': True},
         {'player': 'eve', 'duration_minutes': 18,
          'score': 2661, 'mode': 'competitive', 'completed': True},
         {'player': 'bob', 'duration_minutes': 52,
          'score': 761, 'mode': 'ranked', 'completed': True},
         {'player': 'eve', 'duration_minutes': 46,
          'score': 2101, 'mode': 'casual', 'completed': True},
         {'player': 'charlie', 'duration_minutes': 117,
          'score': 1359, 'mode': 'casual', 'completed': True}
     ],
     'game_modes': ['casual', 'competitive', 'ranked'],
     'achievements': [
         'first_blood',
         'level_master',
         'speed_runner',
         'treasure_seeker',
         'boss_hunter',
         'pixel_perfect',
         'combo_king',
         'explorer'
     ]
    }
    print()
    print("=== List Comprehension Examples ===")
    print(
        "High scorers (>2000): "
        + str([
            player
            for player, data in everything["players"].items()
            if data["total_score"] > 2000
        ])
    )
    print(
        "Scores doubled: "
        + str([
            data["total_score"] * 2
            for data in everything["players"].values()
        ])
    )
    print(
        "Casuals: "
        + str([
            player
            for player, data in everything["players"].items()
            if data["favorite_mode"] == "casual"
        ])
    )
    print()
    print("=== Dict Comprehension Examples ===")
    scores = {player: everything['players'][player]['total_score']
              for player in everything['players']}
    print(f"Player scores: {scores}")
    score_categories = {8000: "high", 4000: "medium", 0: "low"}
    score_breakdown = {cat: sum(1 for s in scores.values() if s > threshold)
                       for threshold, cat in score_categories.items()}
    print(f"Score categories: {score_breakdown}")
    achi_count = {player: everything['players'][player]['achievements_count']
                  for player in everything['players']}
    print(f"Achievement counts: {achi_count}")
    print()
    print("=== Set Comprehension Examples ===")
    player_set = {player for player in everything['players']}
    print(f"Unique players: {player_set}")
    achi_set = {achi for achi in everything['achievements']}
    print(f"Unique achievements: {achi_set}")
    game_mode_set = {gm for gm in everything['game_modes']}
    print(f"Active game modes: {game_mode_set}")
    print()
    print("=== Combined Analysis ===")
    print(f"Total players: {sum(1 for player in everything['players'])}")
    print(f"Total unique achievements:\
 {sum(1 for achievemnt in everything['achievements'])}")
    sessions = everything["sessions"]
    average_score = sum(s["score"] for s in sessions) / len(sessions)
    print(f"Average score per session: {average_score:.2f}")
    print(*{f"MVP: {sesh['player']} ({sesh['score']}\
 points, {sesh['duration_minutes']} minutes)"
            for sesh in everything['sessions']
            if sesh['score'] == max(sesh['score']
                                    for sesh in everything['sessions'])})
