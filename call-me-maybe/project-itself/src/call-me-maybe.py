import sys
import json
import re
import numpy as np
import time
import argparse
from llm_sdk import Small_LLM_Model


llm = Small_LLM_Model(model_name="Qwen/Qwen3-0.6B")
s = time.time()
a = sum(i**100 for i in range(1000))


def in_venv():
    return sys.prefix != sys.base_prefix


def fn_add_numbers(a: int, b: int) -> int:
    """Add two numbers together and return their sum."""
    return a + b


def fn_greet(name: str) -> str:
    """Generate a greeting message for a person by name."""
    return "Hello " + name


def fn_reverse_string(s: str) -> str:
    """Reverse a string and return the reversed result."""
    s_len = len(s)
    reversed_s = s[s_len::-1]
    return reversed_s


def fn_get_square_root(a: int) -> float:
    """Calculate the square root of a number."""
    return a**(1/2)


def fn_substitute_string_with_regex_og(
        source_string: str, regex: str, replacement: str
) -> str:
    """Replace all occurrences matching a regex pattern in a string."""
    print(source_string, regex, replacement)
    result = ""
    regex_len = len(regex)
    source_len = len(source_string)
    to_skip = 0
    for x in range(source_len):
        if source_string[x:x+regex_len] == regex:
            result += replacement
            to_skip = regex_len - 1
        elif to_skip > 0:
            to_skip -= 1
            continue
        else:
            result += source_string[x:x+1]
    return result


def fn_substitute_string_with_regex(
        source_string: str, regex: str, replacement: str
) -> str:
    """Replace all occurrences matching a regex pattern in a string."""
    result = re.sub(regex, replacement, source_string)
    return result


def get_function_by_name(name):
    if name == "fn_add_numbers":
        return fn_add_numbers
    if name == "fn_greet":
        return fn_greet
    if name == "fn_reverse_string":
        return fn_reverse_string
    if name == "fn_get_square_root":
        return fn_get_square_root
    if name == "fn_substitute_string_with_regex":
        return fn_substitute_string_with_regex


TOOLS = {
    "fn_add_numbers": fn_add_numbers,
    "fn_greet": fn_greet,
    "fn_reverse_string": fn_reverse_string,
    "fn_get_square_root": fn_get_square_root,
    "fn_substitute_string_with_regex": fn_substitute_string_with_regex
}


TOOLS_DESCRIPTION = """
You are a tool-calling assistant.

If the user request can be solved with a tool,
respond ONLY with valid JSON.

Available tools:

fn_add_numbers(a: int, b: int)
Description: Add two numbers together.
Example:
{"function":"fn_add_numbers","arguments":{"a":1,"b":2}}

fn_greet(name: str)
Description: "Generate a greeting message for a person by name."
Example:
{"function":"fn_greet","arguments":{"name":"Shrek"}}

fn_reverse_string(s: str)
Description: "Reverse a string and return the reversed result."
Example:
{"function":"fn_reverse_string","arguments":{"s":"abc"}}

fn_get_square_root(a: int)
Description: "Calculate the square root of a number."
Example:
{"function":"fn_get_square_root","arguments":{"a":9}}

fn_substitute_string_with_regex(source_string: str, regex: str, replacement: str)
Description: "Replace all occurrences matching a regex pattern in a string."
Example:
{"function":"fn_substitute_string_with_regex","arguments":{"source_string":"Lo", "regex":"o", "replacement":"L"}}

Do not explain.
Do not add text before or after the JSON.
"""


def generate(prompt, max_tokens=70):
    tokens = llm.encode(prompt)[0].tolist()
    prompt_len = len(tokens)

    for _ in range(max_tokens):
        logits = llm.get_logits_from_input_ids(tokens)
        next_token = int(np.argmax(logits))
        tokens.append(next_token)
        text = llm.decode(tokens[prompt_len:])
        if "}" in text:
            break
    return llm.decode(tokens[prompt_len:])


def try_tool_call(response: str):
    try:
        data = json.loads(response)
    except json.JSONDecodeError:
        print("JSON error, returning base response")
        return response
    fn_name = data.get("function")
    args = data.get("arguments", {})
    if fn_name not in TOOLS:
        return "Unknown function"

    result = TOOLS[fn_name](**args)

    return f"Tool result: {result}", fn_name, args


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("--functions_definition")
    parser.add_argument("--input")
    parser.add_argument("--output")

    args = parser.parse_args()

    if args.functions_definition is None:
        args.functions_definition = "data/input/functions_definition.json"
    if args.input is None:
        args.input = "data/input/function_calling_tests.json"
    if args.output is None:
        args.output = "data/output/function_calls.json"
    with open(args.functions_definition, "r") as file:
        data = json.load(file)
    # print(json.dumps(data, indent=4))
    # prompt_tools = json.dumps(data, indent=4)
    with open(args.input, "r") as test_file:
        test_json = json.load(test_file)
    # prompt_list = json.dumps(test_json)
    with open(args.output, "w") as out_file:
        json_template = []
        for prompt in [entry["prompt"] for entry in test_json]:
            llm_input = f"{TOOLS_DESCRIPTION}\nUser request:\n{prompt}\nResponse:\n"
            response = generate(llm_input)
            after_tool, tool_used, tool_args = try_tool_call(response)
            json_template.append({"prompt": prompt, "name": tool_used, "parameters": tool_args})
            print(after_tool)
        json.dump(json_template, out_file, indent=4)
    print((time.time() - s) * 1e3, "ms")


if __name__ == "__main__":
    if in_venv():
        print("======in venv======")
        main()
    else:
        print("======windows or not venv======")
        try:
            main()
        except Exception as e:
            print(f"ヤバい {e}")
