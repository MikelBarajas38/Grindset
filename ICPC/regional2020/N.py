N = int(input())

account = input()[1:]
account = account.replace('.', '')
account = int(account)
days = 0

for i in range(N):
    num = input()[1:]
    num = num.replace('.', '')
    num = int(num)

    account += num
    if account % 100 != 0:
        days += 1

print(days)