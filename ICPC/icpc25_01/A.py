import re

s = input()
n = int(input())

ptrn = re.compile(f"({s})+")

for _ in range(n):
    p = input()

    if re.match(ptrn, p):
        print("Yes")
    else:
        print("No")
