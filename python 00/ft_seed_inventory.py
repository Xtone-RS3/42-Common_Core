def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    print(seed_type.title() + " seeds: ", end='')
    print(quantity, end=' ')
    if unit == "packets":
        print("packets available")
    elif unit == "grams":
        print("grams total")
    elif unit == "area":
        print("square meters")
    else:
        print("Unknown unit type")
