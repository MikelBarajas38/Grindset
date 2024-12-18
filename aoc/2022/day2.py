def parse(input):
    data = input.split('\n')
    return [*map(lambda x: tuple(x.split(' ')), data)]

def eval_turn(turn):
    opponent = ord(turn[0]) - ord('A')
    player = ord(turn[1]) - ord('X')

    if player == (opponent + 1) % 3 :
        result = 6
    elif player == opponent:
        result = 3
    else:
        result = 0

    return result + player + 1

def part_one(turns):
    return sum(map(eval_turn, turns))

def find_move(turn):
    offset = 0
    if turn[1] == 'Z':
        offset = 1 if turn[0] != 'C' else -2
    elif turn[1] == 'X':
        offset = -1 if turn[0] != 'A' else 2
    
    return (turn[0], chr(ord(turn[0]) + 23 + offset))   

def part_two(turns):
    turns = [*map(find_move, turns)]
    return part_one(turns)

if __name__ == '__main__':

    with open('data.in', 'r') as f:
        input = f.read().strip()

    turns = parse(input)
    print(part_one(turns))
    print(part_two(turns))