T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    total = sum(A)
    found = False
    
    for x in A:
        if (total - x) % 2 == 0:
            found = True
            break
    
    print("Yes" if found else "No")