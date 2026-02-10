def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda artifacts: artifacts["name"], reverse=True)  # noqa: E501


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda mages: mages["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda spells: "*" + spells + "*", spells))


def mage_stats(mages: list[dict]) -> dict:
    maximum = max(mages, key=lambda mages: mages['power'])
    minimum = min(mages, key=lambda mages: mages['power'])
    power_sum = sum([mage['power'] for mage in mages])
    return {
        "max_power": {maximum['name']: maximum['power']},
        "min_power": {minimum['name']: minimum['power']},
        "avg_power": power_sum / len(mages)
    }


if __name__ == "__main__":
    artifacts = [
        {'name': 'A Wind Cloak', 'power': 78, 'type': 'armor'},
        {'name': 'Be the Light Prism', 'power': 84, 'type': 'armor'},
        {'name': 'C that Lightning Rod?', 'power': 74, 'type': 'armor'},
        {'name': 'Dz Nuts', 'power': 69, 'type': 'relic'}
    ]
    mages = [
        {'name': 'River', 'power': 85, 'element': 'wind'},
        {'name': 'Sarah', 'power': 100, 'element': 'lightning'},
        {'name': 'Luna', 'power': 81, 'element': 'earth'},
        {'name': 'Zara', 'power': 50, 'element': 'earth'},
        {'name': 'Phoenix', 'power': 52, 'element': 'fire'}
    ]
    spells = ['meteor', 'darkness', 'freeze', 'tornado']
    print([artifacts["name"] for artifacts in artifacts])
    sorted_artifacts = artifact_sorter(artifacts)
    print([sorted_artifacts["name"] for sorted_artifacts in sorted_artifacts])
    print()
    print({mages['name']: mages["power"] for mages in mages})
    result = power_filter(mages, 90)
    lol = {result['name']: result["power"] for result in result}
    print(lol)
    print()
    print(spells)
    transformed_spells = spell_transformer(spells)
    print(transformed_spells)
    print()
    mage_statistics = mage_stats(mages)
    print(mage_statistics)
