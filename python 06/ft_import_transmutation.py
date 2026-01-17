import alchemy
from alchemy.potions import healing_potion as heal
from alchemy.elements import create_water, create_earth, create_fire
from alchemy.potions import strength_potion
# from alchemy.potions import wisdom_potion

if __name__ == "__main__":
    print("=== Import Transmutation Mastery ===")
    print()
    print("Method 1 - Full module import:")
    print("alchemy.elements.create_fire():", alchemy.elements.create_fire())
    print()
    print("Method 2 - Specific function import:")
    print("create_water():", create_water())
    print()
    print("Method 3 - Aliased import:")
    print("heal():", heal())
    print()
    print("Method 4 - Multiple imports:")
    print("create_earth():", create_earth())
    print("create_fire():", create_fire())
    print("strength_potion():", strength_potion())
    print()
    print("All import transmutation methods mastered!")
    # print("lol:", wisdom_potion())
