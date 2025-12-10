class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    try:
        print("Testing PlantError...")
        raise PlantError
    except PlantError:
        print("Caught PlantError: The tomato plant is wilting!")
    print()
    try:
        print("Testing WaterError...")
        raise WaterError
    except WaterError:
        print("Caught WaterError: Not enough water in the tank!")
    print()
    try:
        print("Testing catching all garden errors...")
        raise PlantError
        raise WaterError
    except (PlantError, WaterError):
        print("Caught PlantError: The tomato plant is wilting!")
        print("Caught WaterError: Not enough water in the tank!")
    print()
    print("All custom error types work correctly!")
