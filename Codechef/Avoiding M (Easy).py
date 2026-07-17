import sys

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

MOD = 998244353

for _ in range(T):
    N = int(data[index])
    M = int(data[index + 1])
    index += 2
    
    if M == 0:
        # MEX=0 impossible? but constraints M>=1
        print(0)
        continue
    
    # dp[i][d]: ways for first i positions, current block has d distinct smalls (d < M)
    # i up to N, d up to M-1
    dp = [[0] * M for _ in range(N + 1)]
    dp[0][0] = 1
    
    num_small = M
    num_large = N - M
    num_special = 1  # M itself
    
    for i in range(N):
        for d in range(M):
            if dp[i][d] == 0:
                continue
            ways = dp[i][d]
            
            # Add large: d unchanged
            if num_large > 0:
                dp[i + 1][d] = (dp[i + 1][d] + ways * num_large) % MOD
            
            # Add small
            # repeat
            if d > 0:
                dp[i + 1][d] = (dp[i + 1][d] + ways * d) % MOD
            # new
            if d < M - 1:
                new_d = d + 1
                add_new = num_small - d
                dp[i + 1][new_d] = (dp[i + 1][new_d] + ways * add_new) % MOD
            
            # Add special M: reset to d=0
            dp[i + 1][0] = (dp[i + 1][0] + ways) % MOD  # *1
    
    # Sum all at N
    ans = 0
    for d in range(M):
        ans = (ans + dp[N][d]) % MOD
    print(ans)