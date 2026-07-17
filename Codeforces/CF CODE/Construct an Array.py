import sys

input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1

for _ in range(t):
    n = int(data[index])
    index += 1
    arr = []
    x = 1
    while len(arr) < n:
        if x % 3 != 0:
            arr.append(x)
        x += 1
    print(' '.join(map(str, arr)))