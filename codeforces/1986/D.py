def solve():
    n = int(input())
    s = input()

    if n <= 2:
        if s[0] == '0':
            s = s[1:]
        print(s)
        return
    
    ans = 10000000000

    for stdn_index in range(n-1):
        
        final_expression = 0

        for i in range(n):

            if s[i] == '1' and stdn_index != i or stdn_index + 1 == i:
                continue

            if i == stdn_index:

                num = s[i:i+2]

                if num[0] == '0':
                    num = num[1]

                if num == '1':
                    continue

            else:

                num = s[i]

            if num == '0':
                print(0)
                return

            final_expression += int(num)

        if final_expression == 0:
            final_expression = 1

        ans = min(ans, final_expression)
    
    print(ans)
    

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()