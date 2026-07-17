import sys
from bisect import bisect_left
INF = 10**30
def solve():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    out = []
    for _ in range(t):
        n = next(it)
        a = [next(it) for _ in range(n)]
        ans = 0
        for i, x in enumerate(a, start=1):
            ans += x * i * (n - i + 1)
        B = [0] * (n + 1)
        for i in range(1, n + 1):
            B[i] = B[i - 1] + (-a[i - 1] if a[i - 1] < 0 else 0)
        prefB = [0] * (n + 1)
        for i in range(n + 1):
            prefB[i] = B[i] + (prefB[i - 1] if i else 0)
        E = [-INF] * n
        for i in range(n):
            if a[i] > 0:
                E[i] = B[i] - a[i]
        pg = [-1] * n
        st = []
        for i in range(n):
            while st and E[st[-1]] <= E[i]:
                st.pop()
            pg[i] = st[-1] if st else -1
            st.append(i)
        ng = [n] * n
        st = []
        for i in range(n - 1, -1, -1):
            while st and E[st[-1]] < E[i]:
                st.pop()
            ng[i] = st[-1] if st else n
            st.append(i)
        H = 0
        for i in range(n):
            if a[i] <= 0:
                continue
            val = E[i]
            l = pg[i]
            rcount = ng[i] - i
            left_t = l + 1  
            right_t = i     
            k = bisect_left(B, val, left_t, right_t + 1) - 1
            if k >= left_t:
                cnt = k - left_t + 1
                sumB = prefB[k] - (prefB[left_t - 1] if left_t else 0)
                contrib_left = cnt * val - sumB
                H += rcount * contrib_left
        ans += 2 * H
        out.append(str(ans))

    sys.stdout.write("\n".join(out))

solve()