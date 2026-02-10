from functools import wraps
import random
import time


def spell_timer(func: callable) -> callable:
    begin = time.time()

    @wraps(func)
    def with_logging(*args, **kwargs):
        print("Casting " + args[1] + "...")
        end = time.time()
        print(f"Spell completed in {end - begin} seconds")
        return func(*args, **kwargs)
    return with_logging


def power_validator(min_power: int) -> callable:
    def decorator(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            for arg in args:
                if type(arg).__name__ == "int":
                    if arg >= min_power:
                        return func(*args, **kwargs)
                    else:
                        return "Insufficient power for this spell"
            return "double check your spell buddy"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> callable:
    def decorator(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            attempt = 0
            roll = random.randint(0, 1)
            while attempt != max_attempts:
                if roll == 1:
                    return func(*args, **kwargs)
                attempt += 1
                print(f"Spell failed, retrying... (attempt {attempt}/{max_attempts})")  # noqa: E501
            raise Exception(f"Spell casting failed after {max_attempts} attempts")  # noqa: E501
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if all(c.isalpha() or c.isspace() for c in name) and len([c for c in name]) >= 3:  # noqa: E501
            return True
        return False

    @spell_timer
    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power!"


if __name__ == "__main__":
    print("Testing spell_timer and power_validator...")
    sarah2015 = MageGuild()
    print(sarah2015.cast_spell("Firaga", 40))
    print()
    print(sarah2015.cast_spell("Firaga", 5))
    print()
    print("Testing retry_spell...")

    @retry_spell(1)
    def lmao():
        return "harrE pottah!"
    try:
        print(lmao())
    except Exception as e:
        print(e)
    print()
    print("Testing name validator...")
    print(
        "Harry Pottah:",
        MageGuild().validate_mage_name("Harry Pottah")
    )
    print(
        "Harry&Pottah:",
        MageGuild().validate_mage_name("Harry&Pottah")
    )
    print(
        "Ha:",
        MageGuild().validate_mage_name("Ha")
    )
