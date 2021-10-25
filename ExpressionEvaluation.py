#Jacob and Me: 34 points

import re

def seperate_string_number(string):
    previous_character = string[0]
    groups = []
    newword = string[0]
    for x, i in enumerate(string[1:]):
        if i.isalpha() and previous_character.isalpha():
            newword += i
        elif i.isnumeric() and previous_character.isnumeric():
            newword += i
        else:
            groups.append(newword)
            newword = i

        previous_character = i

        if x == len(string) - 2:
            groups.append(newword)
            newword = ''
    return groups


def start_valid(arr):
    if arr[0] == ")" or arr[0] == "+" or arr[0] == "-" or arr[0] == "*":
        return False
    else:
        return True


def is_op(el):
    return el == "*" or el == "+" or el == "-"


def double_ops(arr):
    if len(arr) < 2:
        return True

    for i in range(len(arr) - 1):
        if is_op(arr[i]) and is_op(arr[i+1]):
            return False

    return True


def valid_parenthesis(arr):
    if len(arr) < 2:
        return True

    if len(arr) == 2:
        x = "()"
        if str(arr) == x:
            return False

    brackets = []
    for i in range(len(arr) - 1):
        p1 = arr[i]
        p2 = arr[i+1]

        if arr[i] == "(" and arr[i+1] == ")":
            return False

        if arr[i] == "(" and (arr[i+1] == "+" or arr[i+1] == "-" or arr[i+1] == "*"):
            return False

        if arr[i].isdigit() and arr[i+1] == "(":
            return False

        if arr[i] == "(":
            brackets.append(arr[i])

        if arr[i+1] == ")":
            if len(brackets) == 0:
                return False
            else:
                brackets.pop()

    return len(brackets) == 0


def calculate(string):
    string1 = filter(None, re.split(r'([+\-*/()\$])', (string + '$').replace(' ', '')))

    splitted_array = seperate_string_number(string)
    if not start_valid(splitted_array):
        return "invalid"

    if not double_ops(splitted_array):
        return "invalid"

    if not valid_parenthesis(splitted_array):
        return "invalid"

    return do_calculate(string1)


def do_calculate(s):
    stack = []
    num, sign = 0, '+'

    def calculate_top():
        if sign == '+':
            stack.append(num)
        if sign == '-':
            stack.append(-num)
        if sign == '*':
            stack[-1] *= num
            
            stack[-1] = int(stack[-1] / num)

    while c := next(s):
        if c.isdigit():
            num = int(c)
        elif c == '(':
            num = do_calculate(s)
        elif c in ')$':
            calculate_top()
            return sum(stack)
        elif c in '+-*':
            calculate_top()
            sign = c

P = 1000000007
t = int(input())
while t:
    s = input()
    ans = calculate(s)
    if isinstance(ans, str):
        print(ans)
    else:
        if ans < 0:
            ans += P
            ans %= P

        print(str(ans))
    t -= 1
