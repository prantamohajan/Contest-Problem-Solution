# cook your dish here
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    A = input().strip()
    B = input().strip()
    ans = ""
    for i in range(min(n, m)):
        if A[i] == B[i]:
            ans += A[i]
        else:
            break
    
    print(ans)