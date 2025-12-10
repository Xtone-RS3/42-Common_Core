def check_temperature(temp_str):
    temp_int = 0
    try:
        temp_int = int(temp_str)
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")
        print()
        return
    if 0 <= temp_int <= 40:
        print(f"Temperature {temp_int}°C is perfect for plants!")
        print()
        return
    elif temp_int < 0:
        print(f"Error: {temp_int}°C is too cold for plants (min 0°C)")
        print()
        return
    elif temp_int > 40:
        print(f"Error: {temp_int}°C is too hot for plants (max 40°C)")
        print()
        return


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    print()
    check_temperature(input("Testing temperature: "))
    check_temperature(input("Testing temperature: "))
    check_temperature(input("Testing temperature: "))
    check_temperature(input("Testing temperature: "))
    print("All tests completed - program didn't crash!")
