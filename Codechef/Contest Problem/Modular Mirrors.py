import sys

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

for _ in range(T):
    N = int(data[index])
    M = int(data[index + 1])
    index += 2
    
    # Check if possible
    if (N + 1) % 6 == 0 or (N + 1) % 6 == 3:
        # Construct array with S = 1
        arr = []
        for i in range(1, N + 1):
            pos = i % 6
            if pos == 1 or pos == 2:
                arr.append(1)
            elif pos == 3 or pos == 0:  
                arr.append(0)
            else:  # pos 4 or 5 → -1 mod M
                arr.append(M - 1)
        # Output the array
        print(' '.join(map(str, arr)))
    else:
        print(-1)