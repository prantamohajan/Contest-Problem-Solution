import sys
input = sys.stdin.readline

def make_palindrome(half: int, L: int) -> int:
    s = str(half)
    if L % 2 == 1:
        return int(s + s[-2::-1])
    else:
        return int(s + s[::-1])
def solve():
    n = int(input())
    r = n % 12
    sn = str(n)
    length = len(sn)

    for L in range(1, length + 1):
        half_len = (L + 1) // 2
        lo = 10 ** (half_len - 1) if half_len > 1 else 0

        if L < length:
            best_half = 10 ** half_len - 1 
        else:
            best_half = int(sn[:half_len])
        for delta in range(20):
            h = best_half - delta
            if h < lo:
                break
            p = make_palindrome(h, L)
            if p <= n and p % 12 == r:
                print(p, n - p)
                return
    print(-1)
t = int(input())
for _ in range(t):
    solve()