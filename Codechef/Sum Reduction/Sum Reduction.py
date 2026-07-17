T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    arr = A[:]
    changed = True
    while len(arr) > 1 and changed:
        changed = False
        new_arr = []
        used = [False] * len(arr)
        
        for i in range(len(arr)):
            if used[i]:
                continue
            merged = False
            for j in range(i + 1, len(arr)):
                if not used[j] and (arr[i] & arr[j]) == 0:
                    new_arr.append(arr[i] + arr[j])
                    used[i] = used[j] = True
                    merged = True
                    changed = True
                    break
            if not merged and not used[i]:
                new_arr.append(arr[i])
                used[i] = True
        
        arr = new_arr
    
    print("Yes" if len(arr) == 1 else "No")