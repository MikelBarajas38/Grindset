import re

def part_one(input):
    sum = 0
    for line in input.split('\n'):
        digits = re.findall(r'\d', line)
        sum += int(digits[0] + digits[-1])
    return sum

def part_two(input):
    val = {'one':'1', 'two':'2', 'three':'3', 'four':'4', 'five':'5', 'six':'6', 'seven':'7', 'eight':'8', 'nine':'9'}
    sum = 0
    for line in input.split('\n'):
        # positive lookahead for overlapping digits (ex. oneight)
        digits = re.findall(r'(?=(one|two|three|four|five|six|seven|eight|nine|\d))', line)
        lhs = digits[0] if digits[0].isnumeric() else val[digits[0]]
        rhs = digits[-1] if digits[-1].isnumeric() else val[digits[-1]]
        sum += int(lhs + rhs)
    return sum

if __name__ == '__main__':

    with open('data.in', 'r') as f:
        input = f.read().strip()
    
    #print(part_one(input))
    print(part_two(input))