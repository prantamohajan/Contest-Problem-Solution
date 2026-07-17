import sys
input = sys.stdin.read
data = input().split()
index = 0
multTestQ = int(data[index])
index += 1
for _ in range(multTestQ):
    n = int(data[index])
    index += 1
    c = []
    for i in range(n):
        c.append(int(data[index]))
        index += 1
    sum_multi = 0
    s = 0
    num_m = 0
    multis = []
    total = 0
    for ci in c:
        total += ci
        if ci >= 2:
            sum_multi += ci
            num_m += 1
            multis.append(ci)
        else:
            s += 1
    if total < 3:
        print(0)
        continue
    if num_m == 0:
        print(0)
        continue
    extra = 0
    if num_m == 1:
        extra = min(s, sum_multi // 2)
    else:
        for ci in multis:
            extra += (ci - 2) // 2
        extra = min(extra, s)
    candidate = sum_multi + extra
    if candidate < 3:
        print(0)
    else:
        print(candidate)