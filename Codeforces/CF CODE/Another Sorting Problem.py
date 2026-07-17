import sys

input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

results = []

for _ in range(t):
    n = int(data[index])
    index += 1
    a = [int(data[index + i]) for i in range(n)]
    index += n

    is_sort = True
    max_l = 0
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            is_sort = False
            max_l = max(max_l, a[i] - a[i + 1])
    
    if is_sort:
        results.append("YES")
        continue
    
    prev = float('-inf')  
    possible = True
    for i in range(n):
        if a[i] >= prev:
            prev = a[i]
        elif a[i] + max_l >= prev:
            prev = a[i] + max_l
        else:
            possible = False
            break
    
    if possible:
        results.append("YES")
    else:
        results.append("NO")

for res in results:
    print(res)