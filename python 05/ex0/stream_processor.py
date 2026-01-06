from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataProcessor(object):
    def process(self, data: Any) -> str:
        """
        docstring
        """
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """
        docstring
        """
        pass

    @abstractmethod
    def format_output(self, result: str) -> str:
        """
        docstring
        """
        pass


class NumericProcessor(DataProcessor):
    """
    docstring
    """
    pass


class TextProcessor(DataProcessor):
    """
    docstring
    """
    pass


class LogProcessor(DataProcessor):
    """
    docstring
    """
    pass


if __name__ == "__main__":
    pass
