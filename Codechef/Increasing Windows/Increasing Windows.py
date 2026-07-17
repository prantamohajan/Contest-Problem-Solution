import sys

MOD = 998244353
MAXN = 200000

# factorials and inverse factorials
fact = [1] * (MAXN + 1)
for i in range(1, MAXN + 1):
    fact[i] = fact[i - 1] * i % MOD

inv_fact = [1] * (MAXN + 1)
inv_fact[MAXN] = pow(fact[MAXN], MOD - 2, MOD)
for i in range(MAXN, 0, -1):
    inv_fact[i - 1] = inv_fact[i] * i % MOD


def nCr(n, r):
    if r < 0 or r > n:
        return 0
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD


def solve():
    data = sys.stdin.buffer.read().split()
    t = int(data[0])
    idx = 1

    out = []

    for _ in range(t):
        N = int(data[idx])
        K = int(data[idx + 1])
        idx += 2

        ans = 0

        prev = 0  # (t-1)^K
        for x in range(1, K + 1):
            cur = pow(x, K, MOD)

            ways_first = (cur - prev) % MOD
            ways_suffix = nCr(N - x, N - K)

            ans = (ans + ways_first * ways_suffix) % MOD

            prev = cur

        out.append(str(ans))

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()