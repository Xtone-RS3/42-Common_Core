def mage_counter() -> callable:
    n = 0

    def lol():
        nonlocal n
        n += 1
        return n
    return lol


def spell_accumulator(initial_power: int) -> callable:
    def lol(increment: int) -> int:
        nonlocal initial_power
        initial_power += increment
        return initial_power
    return lol


def enchantment_factory(enchantment_type: str) -> callable:
    def lol(base):
        return f"{enchantment_type} {base}"
    return lol


def memory_vault() -> dict[str, callable]:
    the_dict = {}

    def store(key, value):
        the_dict[key] = value
        return the_dict

    def recall(key):
        try:
            return the_dict[key]
        except Exception:
            return "Memory not found"

    return {
        "store": store,
        "recall": recall
    }


if __name__ == "__main__":
    print("Testing mage counter...")
    m_c = mage_counter()
    print(m_c())
    print(m_c())
    print()
    print("Testing spell accumulator...")
    spell_acc = spell_accumulator(100)
    print(spell_acc(100))
    print(spell_acc(50))
    print()
    print("Testing enchantment factory...")
    enchant = enchantment_factory("flaming")
    print(enchant("sword"))
    enchant = enchantment_factory("forsen")
    print(enchant("shield"))
    print()
    print("Testing memory vault...")
    memory = memory_vault()
    print(
        "Before assignemnt:",
        memory["recall"]("name")
    )
    print("Assigning: Name = slim shady")
    memory["store"]("name", "slim shady")
    print(
        "Checking 'Name':",
        memory["recall"]("name")
    )
