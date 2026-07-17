# cook your dish here
t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))

    ans = 0

    for a in arr:
        if a % x == 0:
            ans = max(ans, a)

    print(ans)