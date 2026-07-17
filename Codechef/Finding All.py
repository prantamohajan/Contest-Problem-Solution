import sys
input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

for _ in range(T):
    N = int(data[index])
    index += 1
    A = [int(data[index + i]) for i in range(N)]
    index += N
    
    cnt_m = A.count(-1)
    cnt_z = A.count(0)
    cnt_p = A.count(1)
    
    possible = set()
    
    if cnt_m == 0 and cnt_p == 0:
        possible.add(0)
    elif cnt_m == 0:
        possible.add(-1)
    elif cnt_p == 0:
        possible.add(1)
    else:
        # both at least 1
        possible.add(0)
        if cnt_p >= 2:
            possible.add(-1)
        if cnt_m >= 2:
            possible.add(1)
    
    res = sorted(possible)
    print(' '.join(map(str, res)))