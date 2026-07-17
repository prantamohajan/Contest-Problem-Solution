import math

t = int(input())
for _ in range(t):
    n, x, y, z = map(int, input().split())
    t1 = math.ceil(n / (x + y))
    remaining = n - x * z
    if remaining <= 0:
        t2 = z
    else:
        t2 = z + math.ceil(remaining / (x + 10 * y))
    print(min(t1, t2))