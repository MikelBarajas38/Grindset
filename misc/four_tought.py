possible = []

keyboard = [['1','2','3'],
            ['4','5','6'],
            ['7','8','9'],
            ['*','0','*']]

def find_comb(n, i, j, curr):

    if n > 3:
        return

    if j > 2 or i > 3:
        return
    
    if(keyboard[i][j] == '*'):
        return
    
    if n == 3 and int(curr[0]) > 1:
        return

    curr += keyboard[i][j]
    possible.append(int(curr))

    find_comb(n + 1, i, j, curr)
    for k in range(1, 3):
        find_comb(n + 1, i + k, j, curr)
        find_comb(n + 1, i, j + k, curr)

for i in range(3):
    for j in range(3):
        find_comb(1, i, j, '')

possible.sort()
print(possible)