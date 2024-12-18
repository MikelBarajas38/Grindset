import re

def is_valid(cubes):
    return cubes['r'] <= 12 and cubes['g'] <= 13 and cubes['b'] <= 14

def part_one(input):
    sum = 0

    for game in input.split('\n'):
        possible = True
        
        for turn in game.split(';'):
            cubes = {'r': 0, 'g': 0, 'b': 0}
            data = re.findall(r'(\d+) (.)', turn)

            for value, color in data:
                cubes[color] += int(value)

            if not is_valid(cubes):
                possible = False
                break

        if possible:
            sum += int(re.search(r'(\d+)', game).group())

    return sum

def part_two(input):
    sum = 0

    for game in input.split('\n'):
        possible = True
        cubes = {'r': 0 , 'g': 0, 'b': 0}

        for turn in game.split(';'):
            data = re.findall(r'(\d+) (.)', turn)

            for value, color in data:
                cubes[color] = max(int(value), cubes[color])

        sum += cubes['r'] * cubes['g'] * cubes['b']
            
    return sum

if __name__ == '__main__':

    with open('data.in', 'r') as f:
        input = f.read().strip()
    
    print(part_one(input))
    print(part_two(input))