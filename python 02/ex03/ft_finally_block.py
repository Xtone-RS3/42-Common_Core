def water_plants(plant_list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None:
                raise WaterError
            print(f"Watering {plant}")
    except WaterError:
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    print("Testing normal watering...")
    water_plants(["tomato", "lettuce", "carrots"])
    print("Watering completed successfully!")
    print()
    print("Testing with error...")
    water_plants(["tomato", None])
    print()
    print("Cleanup always happens, even with errors!")


class WaterError(Exception):
    pass


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system()
