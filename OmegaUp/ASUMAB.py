def solve():
    n = input()
    n = sorted(n, reverse=True)

    A = ''
    B = ''

    zero_index = 0
    for i in range(len(n)):
        if(n[i] == '0'):
            zero_index = i
            break

        if i % 2 == 0:
            A += n[i]
        else:
            B += n[i]

    if(len(B) == 0):
        B = '0'
        zero_index += 1
 
    A += n[zero_index:]
    
    print(f'{int(A)} + {int(B)} = {int(A) + int(B)}')



def main():
    t = int(input())
    for i in range(t):
        solve()


if __name__ == '__main__':
    main()