from math import sqrt

def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    avg = 0
    for i in a:
        avg += i**2
    avg /= n

    factor = x / avg

    for i in a:
        ans = i * sqrt(factor)
        print(ans, end=' ')

solve()