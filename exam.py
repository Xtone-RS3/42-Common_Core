def crescent(s: str):
    arr = []
    result = 0
    print(s[1:len(s)])
    compare = 1
    # print(s[5])
    for n in range(len(s)):
        print(s[n]+1)
        # if s[n] 



def rotate(s, n):
    result = ""
    n = n % 26
    table = "abcdefghijklmnopqrstuvwxyz"
    hold = 0
    for char in s:
        hold = table.find(char)
        result += table[hold + n]
    return result


def bracket(s):
    while "()" in s or "[]" in s or "{}" in s:
        s = s.replace("()", "")
        s = s.replace("[]", "")
        s = s.replace("{}", "")
    return s == ""


if __name__ == "__main__":
    # print(dir(str.join))
    # print(rotate("abc", 3))
    crescent("1234")
