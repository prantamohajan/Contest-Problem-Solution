T = int(input())
for _ in range(T):
    N = int(input())
    S = input().strip()
    i = 0
    ans = 0
    while i < N:
        j = i
        while j < N and S[j] == S[i]:
            j += 1
        
        length = j - i
        ans += length // 3
        
        i = j
    print(ans)