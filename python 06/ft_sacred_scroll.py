import alchemy


if __name__ == "__main__":
    print("=== Sacred Scroll Mastery ===")
    print()
    print("Testing direct module access:")
    print("alchemy.elements.create_fire():", alchemy.elements.create_fire())
    print("alchemy.elements.create_water():", alchemy.elements.create_water())
    print("alchemy.elements.create_earth():", alchemy.elements.create_earth())
    print("alchemy.elements.create_air():", alchemy.elements.create_air())
    print()
    print("Testing package-level access (controlled by __init__.py)")
    print("alchemy.create_fire():", alchemy.create_fire())
    print("alchemy.create_water():", alchemy.create_water())
    try:
        print("alchemy.create_earth():", alchemy.create_earth())
    except AttributeError:
        print("AttributeError - not exposed")
    try:
        print("alchemy.create_air():", alchemy.create_air())
    except AttributeError:
        print("AttributeError - not exposed")
    print()
    print("Package metadata:")
    print("Version:", alchemy.__version__)
    print("Author:", alchemy.__author__)
