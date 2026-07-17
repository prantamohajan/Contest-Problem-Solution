# cook your dish here
t = int(input())

for _ in range(t):
    x, y, z = map(int, input().split())

    a, b, c = sorted([x, y, z])

    if a + b > c:
        print(0)
    else:
        print(c - (a + b) + 1)