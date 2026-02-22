import importlib
import sys


def in_venv():
    return sys.prefix != sys.base_prefix


if __name__ == "__main__":
    print("LOADING STATUS: Loading programs...")
    print()
    if in_venv():
        pass
    else:
        print("Not in virt env, please create one to test this project")
        print("python3 -m venv matrix_env")
        print("source matrix_env/bin/activate")
        exit()
    try:
        print("Checking dependencies:")
        numpy = importlib.import_module("numpy")
        pandas = importlib.import_module("pandas")
        print(
            "[OK] pandas ",
            f"({pandas.__version__}) - Data manipulation ready"
        )
        requests = importlib.import_module("requests")
        print(
            "[OK] request ",
            f"({requests.__version__}) - Network access ready"
        )
        matplotlib = importlib.import_module("matplotlib")
        pyplot = importlib.import_module("matplotlib.pyplot")
        print(
            "[OK] matplotlib ",
            f"({matplotlib.__version__}) - Visualization ready"
        )
    except (ModuleNotFoundError, ImportError) as e:
        print(f"You just caused me to suffer due to: {e}")
        print()
        print("do like: pip install -r requirements.txt")
        print("python3 loading.py")
        print()
        print("or maybe: pip install poetry")
        print("python3 -m poetry install")
        print("python3 loading.py")
        exit(1)
    print()
    print("Analyzing Matrix data...")
    print("Processing 250 data points...")
    xpoints = numpy.array([0, 6])
    ypoints = numpy.array([0, 250])
    matplotlib.pyplot.plot(xpoints, ypoints)
    print("Generating visualization...")
    matplotlib.pyplot.savefig("image")
    print()
    print("Analysis complete!")
    print("Results saved to: image.png")
