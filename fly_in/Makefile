# Variables
PYTHON = python3
MAIN = flyin.py
# Manually override this shit
MAP = maps\easy\01_linear_path.txt

.PHONY: install run debug clean lint lint-strict

install:
	$(PYTHON) -m pip install --upgrade pip
	$(PYTHON) -m pip install mypy
	$(PYTHON) -m pip install flake8

run:
	$(PYTHON) $(MAIN) $(MAP)

debug:
	$(PYTHON) -m pdb $(MAIN) $(MAP)

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type d -name ".mypy_cache" -exec rm -rf {} +
	find . -type d -name ".pytest_cache" -exec rm -rf {} +
	find . -type f -name "*.pyc" -delete

lint:
	flake8 .
	mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict