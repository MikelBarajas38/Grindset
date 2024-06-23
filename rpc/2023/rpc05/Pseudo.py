n, k = map(int, input().split())

ans = 0

for i in range(2**n):

    x = format(i, '0{}b'.format(n))

    past = 'x'
    repeat = 1

    for c in x:

        if past == 'x':
            past = c
            continue
        
        if past == c:
            repeat += 1
        else:
            repeat = 1
        
        if repeat > k:
            break

        past = c

    if repeat <= k:
        ans += 1

print(ans)