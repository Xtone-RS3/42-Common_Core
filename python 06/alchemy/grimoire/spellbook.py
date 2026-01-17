def record_spell(spell_name: str, ingredients: str) -> str:
    """
    docstring
    """
    from .validator import validate_ingredients
    hold = validate_ingredients(ingredients)
    if hold.endswith(" - VALID"):
        return f"Spell recorded: {spell_name} ({hold})"
    else:
        return f"Spell rejected: {spell_name} ({hold})"


# def validate_ingredients_cooler(ingredients: str) -> str:
#     """
#     docstring
#     """
#     for ingred in ingredients.split(" "):
#         if ingred not in ["fire", "air", "water", "earth"]:
#             return f"{ingredients} - INVALID"
#         else:
#             return f"{ingredients} - VALID"
