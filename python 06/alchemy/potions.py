from alchemy.elements import create_fire
from alchemy.elements import create_water, create_earth, create_air


def healing_potion():
    """
    uses fire and water
    """
    return f"Healing potion brewed with {create_fire()} and \
{create_water()}"


def strength_potion():
    """
    uses earth and fire
    """
    return f"Strength potion brewed with {create_earth()} and \
{create_fire()}"


def invisibility_potion():
    """
    uses air and water
    """
    return f"Invisibility potion brewed with {create_air()} and \
{create_water()}"


def wisdom_potion():
    """
    uses fire, water, earth, air
    """
    return f"Wisdom potion brewed with all elements: \
{create_fire(), create_water(), create_earth(), create_air()}"
