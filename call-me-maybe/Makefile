# Variables
PYTHON = python3

.PHONY: install run debug clean lint lint-strict

# install:
# 	$(PYTHON) -m venv venv
# 	source venv/bin/activate
# 	$(PYTHON) -m pip install uv
# 	uv sync --directory llm_sdk --active --no-cache
# 	$(PYTHON) -m pip install accelerate
# 	$(PYTHON) -m pip install mypy
# 	$(PYTHON) -m pip install flake8

run:
	$(PYTHON) -m uv run src/call-me-maybe.py --functions_definition --input --output

debug:
	$(PYTHON) -m uv run src/call-me-maybe.py --functions_definition --input --output

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type d -name ".mypy_cache" -exec rm -rf {} +
	find . -type d -name ".pytest_cache" -exec rm -rf {} +
	find . -type f -name "*.pyc" -delete

lint:
	$(PYTHON) -m flake8 .
	$(PYTHON) -m mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	$(PYTHON) -m flake8 .
	$(PYTHON) -m mypy . --strict