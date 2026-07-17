t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    res = 0
    for i in range(n):
        if ((n - 1) & i) == i:
            res ^= a[i]

    print(res)