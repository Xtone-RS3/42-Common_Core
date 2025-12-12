def check_plant_health(plant_name, water_level, sunlight_hours):
    try:
        if plant_name is None:
            raise ValueError("Error: Plant name cannot be empty")
        if 0<water_level<11:
            pass
        elif water_level>10:
            raise ValueError(f"Error: Water level {water_level} is too high (max 10)")
        elif water_level<1:
            raise ValueError(f"Error: Water level {water_level} is too low (min 1)")
        if 1<sunlight_hours<13:
            pass
        elif sunlight_hours>12:
            raise ValueError(f"Error: Sunlight hours {sunlight_hours} is too high (max 12)")
        elif sunlight_hours<2:
            raise ValueError(f"Error: Sunlight hours {sunlight_hours} is too low (min 2)")
        print(f"Plant '{plant_name}' is healthy!")
    except ValueError as e:
        print(e)


def test_plant_checks():
    print("Testing good values...")
    check_plant_health("tomato", 10, 10)
    print()
    print("Testing empty plant name...")
    check_plant_health(None, 10, 10)
    print()
    print("Testing bad water level...")
    check_plant_health("tomato", 15, 10)
    print()
    print("Testing bad sunlight hours...")
    check_plant_health("tomato", 10, 0)
    print()
    print("All error raising tests completed!")
    

if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===")
    print()
    test_plant_checks()