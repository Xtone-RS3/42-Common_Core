from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return result


class NumericProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid numeric data")
        len_data = len(data)
        sum_data = sum(data)
        return f"Processed {len_data} numeric values, sum={sum_data},\
 avg={sum_data/len_data}"

    def validate(self, data: Any) -> bool:
        try:
            for number in data:
                int(number)
        except ValueError:
            return False
        return True


class TextProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid text data")
        len_data = len(data)
        word_count = len(data.split())
        return f"Processed text: {len_data} characters, {word_count}\
 words"

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        return False


class LogProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid log entry")
        log_type = {"ERROR": "[ALERT]", "INFO": "[INFO]"}
        level, message = data.split(":", 1)
        return f"{log_type[level]} {level} level detected:{message}"

    def validate(self, data: Any) -> bool:
        if isinstance(data, str) and ":" in data:
            return True
        return False


if __name__ == "__main__":
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
    print()
    print("Initializing Numeric Processor...")
    num_test = [1, 2, 3, 4, 5]
    print(f"Processing data: {num_test}")
    number = NumericProcessor()
    try:
        number.process(num_test)
        print("Validation: Numeric data verified")
        print("Output:", number.process(num_test))
    except ValueError as e:
        print(e)
    print()
    text_test = "Hello Nexus World"
    print("Initializing Text Processor...")
    print(f"Processing data: \"{text_test}\"")
    text = TextProcessor()
    try:
        text.process(text_test)
        print("Validation: Text data verified")
        print("Output:", text.process(text_test))
    except ValueError as e:
        print(e)
    print()
    print("Initializing Log Processor...")
    log_test = "ERROR: Connection timeout"
    print(f"Processing data: {log_test}")
    log = LogProcessor()
    try:
        log.process(log_test)
        print("Validation: Text data verified")
        print("Output:", log.process(log_test))
    except ValueError as e:
        print(e)
    print()
    print("=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")
    num2 = NumericProcessor()
    text2 = TextProcessor()
    log2 = LogProcessor()
    print("Result 1: " + num2.format_output(num2.process([1, 2, 3])))
    print("Result 2: " + text2.format_output(text2.process("lol, lmao even")))
    print("Result 3: " +
          log2.format_output(log2.process("INFO: System ready")))
    print()
    print("Foundation systems online. Nexus ready for advanced streams.")
