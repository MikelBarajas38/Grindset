import random

def main():

    N = 100
    caramels = [random.randint(1, 100) for _ in range(N)]
    caramel_sum = sum(caramels)

    if caramel_sum % 2 == 1:
        for i in range(N):
            if caramels[i] < 100:
                caramels[i] += 1
                break

    print(N)
    print(*caramels)

if __name__ == '__main__':
    main()