def spell_combiner(spell1: callable, spell2: callable) -> callable:
    return lambda *args, **kwargs: (spell1(*args, **kwargs), spell2(*args, **kwargs))  # noqa: E501


def power_amplifier(base_spell: callable, multiplier: int) -> callable:
    return lambda x=10: base_spell(x) * multiplier


def conditional_caster(condition: callable, spell: callable) -> callable:
    return lambda target_name: spell(target_name) if condition(target_name) else "Spell fizzled"  # noqa: E501


def spell_sequence(spells: list[callable]) -> callable:
    return lambda emote: spells(emote)


def fireb(power=10) -> int:
    return power


def S_Spell_cond(target_name: str) -> bool:
    if target_name.startswith("S"):
        return True
    else:
        return False


def lightning_bolt(emote: str = "forsenGa") -> str:
    return f"{emote} lightningbolt!"


def bacon(emote: str = "pepepains") -> str:
    return f"{emote} bacon is good for me"


def potato(emote: str = "pepepains") -> str:
    return f"{emote} my life is potato"


def next_step_of_plan(emote: str = "pepepains") -> str:
    return f"{emote} CRASHING THIS PLANE"


def never_doubt(emote: str = "forsenSmug") -> str:
    return f"{emote} smugTime 15:28"


def S_Spell(target_name: str):
    return f"{target_name} got its S attacked!"


if __name__ == "__main__":
    test_values = [11, 17, 10]
    test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']
    lightning_heal = spell_combiner(
        lambda target: f"Lightning bolt hits {target}",
        lambda target: f"Heals {target}"
    )
    print("Testing spell combiner...")
    print(
        "Combined spell result:",
        lightning_heal("Giant Enemy Crab")
    )
    print()
    unlimited_powah = power_amplifier(lambda x: fireb(x), 3)
    print("Testing power amplifier...")
    print(
        "Original:",
        fireb(),
        "Amplified:",
        unlimited_powah(10)
    )
    print()
    print("Testing conditinal spells...")
    consssssion = conditional_caster(lambda target_name: S_Spell_cond(target_name), lambda target_name: S_Spell(target_name))  # noqa: E501
    print(consssssion("Snake"))
    print()
    print("Testing sequence spells...")
    forsen_lines = spell_sequence(lambda emote: [bacon(emote), potato(emote), next_step_of_plan(emote), never_doubt()])  # noqa: E501
    print(forsen_lines("pepepains"))
