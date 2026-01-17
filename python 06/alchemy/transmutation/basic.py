from alchemy.elements import create_fire, create_earth


def lead_to_gold():
    """
    create gold from appying fire to lead
    """
    return f"Lead transmuted to gold using {create_fire()}"


def stone_to_gem():
    """
    create a gem from appling fire to a ROCK
    """
    return f"Stone transmuted to gem using {create_earth()}"
