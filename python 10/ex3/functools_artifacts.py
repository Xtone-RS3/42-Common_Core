from functools import reduce, partial, lru_cache, singledispatch
import time
from typing import Any


def max_func(x, y):
    if x > y:
        return x
    return y


def min_func(x, y):
    if x > y:
        return y
    return x


def spell_reducer(spells: list[int], operation: str) -> int:
    result = 0
    if operation == "sum":
        result = reduce(lambda x, y: x + y, spells)
    elif operation == "product":
        result = reduce(lambda x, y: x * y, spells)
    elif operation == "max":
        result = reduce(max_func, spells)
    elif operation == "min":
        result = reduce(min_func, spells)
    return result


def base_enchantment(power: int = 50, enchantment: str = "lightning bolt", name: str = "sword") -> str:  # noqa: E501
    return f"{name} got enchanted with {enchantment} at {power} power!"


def partial_enchanter(base_enchantment: callable) -> dict[str, callable]:
    return {
        "eletric_enchantment": partial(base_enchantment, 50, "eletric"),
        "fire_enchantment": partial(base_enchantment, 50, "fire"),
        "ice_enchantment": partial(base_enchantment, 50, "ice")  # LOOK! -> 50 arg2 | "ice" arg3  # noqa: E501
    }  # LOOK!                      ^ "Shield" gets put here


@lru_cache(maxsize=128)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def regular_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return regular_fibonacci(n - 1) + regular_fibonacci(n - 2)


def spell_dispatcher() -> callable:
    @singledispatch
    def dispatcher(arg: Any) -> str:
        return f"IDK what to do with this '{type(arg).__name__}' input man..."

    @dispatcher.register(int)
    def _(arg: int):
        return f"Lightningbolt deals {arg} damage"

    @dispatcher.register(str)
    def _(arg: str):
        return f"Weapon enchated with {arg}"

    @dispatcher.register(list)
    def _(arg: list):
        return [dispatcher(arg) for arg in arg]
    return dispatcher


if __name__ == "__main__":
    print("Testing spell reducer...")
    reducer_mult = spell_reducer([6, 1, 2, 3, 4, 5], "product")
    print(
        "Product:",
        reducer_mult
    )
    reducer_sum = spell_reducer([6, 1, 2, 3, 4, 5], "sum")
    print(
        "Sum:",
        reducer_sum
    )
    reducer_max = spell_reducer([6, 1, 2, 3, 4, 5], "max")
    print(
        "Max:",
        reducer_max
    )
    reducer_min = spell_reducer([6, 1, 2, 3, 4, 5], "min")
    print(
        "Min:",
        reducer_min
    )
    print()
    print("Testing partial enchanter...")
    partial_test = partial_enchanter(base_enchantment)
    print(partial_test["ice_enchantment"]("Shield"))  # LOOK! -> Shield == arg1
    # ^so the "ice_enchantment" will decide which route we go down
    # and then the "Shield" gets passed along with anything in that route down into the base enchanter function!  # noqa: E501
    print(partial_test["fire_enchantment"]("Bow"))  # keys must be in the "route", but the *item* does not  # noqa: E501
    print()
    print("Testing memorized fibonacci")
    begin = time.time()
    print(memoized_fibonacci(29))
    end = time.time()
    print(f"Memorized fibonacci took {end - begin} to calc that")
    begin = time.time()
    print(regular_fibonacci(29))
    end = time.time()
    print(f"Regular fibonacci took {end - begin} to calc that")
    print()
    print("Testing spell dispatcher...")
    dispatched_thingy = spell_dispatcher()
    print(dispatched_thingy(1))
    print(dispatched_thingy("hmmmm"))
    print(dispatched_thingy(["fire", 1, "wind"]))
    print(dispatched_thingy({"hmmmm": 1}))
