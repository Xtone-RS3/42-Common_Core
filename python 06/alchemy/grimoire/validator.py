def validate_ingredients(ingredients: str) -> str:
    """
    docstring
    """
    for ingred in ingredients.split(" "):
        if ingred not in ["fire", "air", "water", "earth"]:
            return f"{ingredients} - INVALID"
        else:
            return f"{ingredients} - VALID"
