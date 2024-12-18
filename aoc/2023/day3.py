import re

def in_bounds(engine, i , j):
    return i >= 0 and i < len(engine) and j >= 0 and j < len(engine[0])

def dfs(engine, visited, i, j):
    if not in_bounds(engine, i, j) or engine[i][j] == '.' or visited[i][j] == 1:
        return

    visited[i][j] = 1

    di = [-1, -1, -1, 0, 0, 1, 1, 1]
    dj = [-1, 0, 1, -1, 1, -1, 0, 1]

    for k in range(8):
        dfs(engine, visited, i + di[k], j + dj[k])
    
    if not engine[i][j].isnumeric():
        visited[i][j] = 0
    

def parse(input):
    data = input.split('\n')
    engine = [*map(lambda x: list(x), data)]
    visited = [[0 for _ in range(len(engine[0]))] for _ in range(len(engine))]
    for i in range(len(engine)):
        for j in range(len(engine[0])):
            if engine[i][j] != '.' and not engine[i][j].isnumeric():
                dfs(engine, visited, i, j)
    return engine, visited

def gear_dfs(engine, visited, i, j):
    if not in_bounds(engine, i, j) or engine[i][j] == '.' or visited[i][j] == 1:
        return 0

    visited[i][j] = 1

    di = [-1, -1, -1, 0, 0, 1, 1, 1]
    dj = [-1, 0, 1, -1, 1, -1, 0, 1]

    neigbor_count = 0
    for k in range(8):
        if gear_dfs(engine, visited, i + di[k], j + dj[k]) > 0:
            neigbor_count += 1
    
    if not engine[i][j].isnumeric():
        visited[i][j] = neigbor_count
    
    return 1

def parse_gears(input):
    data = input.split('\n')
    engine = [*map(lambda x: list(x), data)]
    visited = [[0 for _ in range(len(engine[0]))] for _ in range(len(engine))]
    
    for i in range(len(engine)):
        for j in range(len(engine[0])):
            prev_visited = [[visited[i][j] for j in range(len(engine[0]))] for i in range(len(engine))]
            if engine[i][j] == '*':
                gear_dfs(engine, visited, i, j)
                if visited[i][j] != 2:
                    visited = prev_visited

    return engine, visited

def part_one(input):
    sum = 0
    engine, valid = parse(input)
    for i in range(len(engine)):
        for j in range(len(engine[0])):

            if valid[i][j] == 0:
                continue

            number = ''
            nj = j
            while in_bounds(engine, i, nj) and valid[i][nj] == 1:
                valid[i][nj] = 0
                number += engine[i][nj]
                nj += 1
            sum += int(number)

    return sum

def part_two(input):
    sum = 0

    ratios = []
    engine, valid = parse_gears(input)
    for i in range(len(engine)):
        for j in range(len(engine[0])):

            if valid[i][j] != 1:
                continue

            number = ''
            nj = j
            while in_bounds(engine, i, nj) and valid[i][nj] == 1:
                valid[i][nj] = 0
                number += engine[i][nj]
                nj += 1
            ratios.append(int(number))

    for i in range(0, len(ratios) - 1, 2):
        sum += ratios[i] * ratios[i+1]
            
    return sum

if __name__ == '__main__':

    with open('data.in', 'r') as f:
        input = f.read().strip()
    
    print(part_one(input))
    print(part_two(input))

#todo: better to save just indexes of the numbers and then parse them
#test 2