import time


def init_analytics():
    return {
        "high_level_players": {},
        "treasure_count": 0,
        "level_up_count": 0,
        "total_events": 0
    }


def event_analytics(ev, state):
    # print(f"Total events processed: {len(ev_list)}")
    state["total_events"] += 1

    if ev['player'] not in state["high_level_players"]:
        if ev['data']['level'] >= 10:
            state["high_level_players"][ev['player']] = ev['data']['level']
    if ev['event_type'] == "item_found":
        state["treasure_count"] += 1
    if ev['event_type'] == "level_up":
        state["level_up_count"] += 1


def event_processor(ev):
    type_decompression = {
        "kill": "killed monster",
        "death": "has died",
        "level_up": "leveled up",
        "item_found": "found treasure",
        "quest_complete": "completed a quest",
        "login": "logged in",
        "logout": "logged out"
        }
    print(f"Event {ev['id']}: Player {ev['player']}\
 (level {ev['data']['level']}) {type_decompression[ev['event_type']]}")


def event_stream(ev_list):
    for ev in ev_list:
        yield ev


def fibonacci_stream():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


def prime_stream():
    yield 2
    n = 3
    while True:
        is_prime = True
        for i in range(3, int(n ** 0.5) + 1, 2):
            if n % i == 0:
                is_prime = False
                break
        if is_prime:
            yield n
        n += 2


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    ev_list = []  # data here
    state = init_analytics()

    start = time.perf_counter()
    for ev in event_stream(ev_list):
        event_processor(ev)
        event_analytics(ev, state)
    end = time.perf_counter()
    processing_time = end - start
    print()
    print(f"Processing {state['total_events']} game events...")

    print()
    print("=== Stream Analytics ===")
    print(f"Total events processed: {state['total_events']}")
    print(f"High-level players (10+): {len(state['high_level_players'])}")
    print(f"Treasure events: {state['treasure_count']}")
    print(f"Level-up events: {state['level_up_count']}")
    print()
    print("Memory usage: Constant (streaming)")
    print(f"Processing time: {processing_time} seconds")
    print()
    print("=== Generator Demonstration ===")

    n = 10
    print(f"Fibonacci sequence (first {n}): ", end="")
    fib = fibonacci_stream()
    printed = False
    for x in range(n):
        if printed:
            print(", ", end="")
            printed = False
        print(next(fib), end="")
        printed = True
    print()

    n = 5
    print(f"Prime numbers (first {n}): ", end="")
    prime = prime_stream()
    printed = False
    for x in range(n):
        if printed:
            print(", ", end="")
            printed = False
        print(next(prime), end="")
        printed = True
    print()
