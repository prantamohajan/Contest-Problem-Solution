import sys
from functools import lru_cache
input = sys.stdin.readline
def solve():
    n, k = map(int, input().split())
    sv = int(input().strip(), 2)
    zv = int(input().strip(), 2)
    def contrib(t):
        v = (sv if (t >> 1) & 1 else 0) ^ (zv if t & 1 else 0)
        pc = bin(v).count('1')
        return pc * (n - pc)
    contrib_table = [contrib(t) for t in range(4)]
    @lru_cache(maxsize=None)
    def count(depth, L, R):
        if depth == 0:
            c = [0,0,0,0]; c[L] = 1; return tuple(c)
        M = ((L>>1)^(R>>1))<<1 | ((L&1)^(R&1))  
        cl = count(depth-1, L, M)
        cr = count(depth-1, M, R)
        return tuple(cl[i] + cr[i] for i in range(4))
    cnts = list(count(k, 2, 1))
    cnts[1] += 1
    print(sum(cnts[t] * contrib_table[t] for t in range(4)))
T = int(input())
for _ in range(T):
    solve()