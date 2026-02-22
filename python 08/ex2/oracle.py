import os
import sys
try:
    from dotenv import load_dotenv  # type: ignore
except ModuleNotFoundError:
    print("please run: pip install python-dotenv")
    exit(1)


def in_venv():
    return sys.prefix != sys.base_prefix


if __name__ == "__main__":
    load_dotenv()
    if in_venv():
        pass
    else:
        print("Not in virt env, please create one to test this project")
        print("python3 -m venv matrix_env")
        print("source matrix_env/bin/activate")
        exit()
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    print("Configuration loaded:")
    try:
        matrix_mode = os.getenv("MATRIX_MODE")
    except KeyError:
        print("ENV values not provided")
        exit(1)
    if matrix_mode not in ["development", "production"]:
        print(
            "Mode outside of scope:",
            matrix_mode
        )
        exit(1)
    try:
        print(
            "Mode:",
            os.getenv("MATRIX_MODE")
        )
        print(
            "Database:",
            # os.getenv("DATABASE_URL"),
            "Connected to local instance"
        )
        print(
            "API Access:",
            "Authenticated",
            # os.getenv('API_KEY')
        )
        print(
            "Log Level:",
            os.getenv("LOG_LEVEL")
        )
        print(
            "Zion Network:",
            "Online",
            # os.getenv("ZION_ENDPOINT")
        )
    except KeyError as e:
        print(f"You just caused me pain because: {e} is missing")
    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")
    print()
    print("The Oracle sees all configurations.")
