import sys
input = sys.stdin.readline
def solve():
    n = int(input())
    h = list(map(int, input().split()))
    out = []
    for empty in range(n):
        walls = [h[(empty + j) % n] for j in range(n)]
        prefix_max = walls[:]
        for j in range(1, n):
            prefix_max[j] = max(prefix_max[j-1], walls[j])
        suffix_max = walls[:]
        for j in range(n-2, -1, -1):
            suffix_max[j] = max(suffix_max[j+1], walls[j])
        total = sum(min(prefix_max[k], suffix_max[k+1]) for k in range(n-1))
        out.append(total)
    print(*out)
t = int(input())
for _ in range(t):
    solve()