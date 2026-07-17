# cook your dish here
# input
N, K = map(int, input().split())

# required majority
required = (N // 2) + 1

# result
if K >= required:
    print(0)
else:
    print(required - K)