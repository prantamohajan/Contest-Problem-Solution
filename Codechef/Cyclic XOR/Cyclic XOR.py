import sys
from math import gcd
MOD = 998244353
def solve():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    ans = []
    for _ in range(t):
        N = next(it)
        K = next(it)
        d = gcd(N, 1 << K)
        L = N // d
        if L % 3 != 0:
            ans.append("1")
        else:
            ans.append(str(pow(2, 2 * K * d, MOD)))
    print("\n".join(ans))

solve()