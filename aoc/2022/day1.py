def parse(input):
    calories = []
    test = 0

    for line in input.split('\n'):
        if line:
            test += int(line)
        else:
            calories.append(test)
            test = 0 
    calories.append(test)

    return calories

def solution(calories):
    calories.sort(reverse = True)
    return calories[0], calories[0] + calories[1] + calories[2]

if __name__ == '__main__':

    with open('data.in', 'r') as f:
        input = f.read().strip()
    
    calories = parse(input)
    part_one, part_two = solution(calories)
    print(part_one)
    print(part_two)
