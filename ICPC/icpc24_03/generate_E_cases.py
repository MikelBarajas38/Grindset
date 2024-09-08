import random

def rotate_90_clockwise(matrix):
    N = len(matrix)
    for i in range(N):
        for j in range(i, N):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(N):
        matrix[i].reverse()

    return matrix

def main():

    N = 50
    start = random.randint(10000, 100000 - N)

    matrix = [[start + i*N + j for j in range(N)] for i in range(N)]

    for i in range(3):
        matrix = rotate_90_clockwise(matrix)

    print(N)
    for i in range(N):
        for j in range(N):
            print(matrix[i][j], end=' ')
        print()



if __name__ == '__main__':
    main()
