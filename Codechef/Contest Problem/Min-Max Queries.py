import sys

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

for _ in range(T):
    N = int(data[index])
    Q = int(data[index + 1])
    index += 2
    
    A = [0] * (N + 1)
    for i in range(1, N + 1):
        A[i] = int(data[index])
        index += 1
    
    for q in range(Q):
        typ = int(data[index])
        index += 1
        if typ == 1:
            u = int(data[index])
            X = int(data[index + 1])
            index += 2
            A[u] = X
        else:
            L = int(data[index])
            R = int(data[index + 1])
            index += 2
            length = R - L + 1
            if length == 1:
                print(A[L])
                continue
            p = length // 2
            mod6 = length % 6
            if mod6 == 1 or mod6 == 3 or mod6 == 5:
                # width 3: positions p, p+1, p+2 (1-based in subarray)
                # max( min(Ap, Ap+1), min(Ap+1, Ap+2) )
                pos1 = L + p - 1
                pos2 = pos1 + 1
                pos3 = pos1 + 2
                val = max(min(A[pos1], A[pos2]), min(A[pos2], A[pos3]))
                print(val)
            else:
                # width 2: max(Ap, Ap+1)
                pos1 = L + p - 1
                pos2 = pos1 + 1
                val = max(A[pos1], A[pos2])
                print(val)