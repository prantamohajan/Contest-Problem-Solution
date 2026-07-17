import sys

input = sys.stdin.read
data = input().split()

T = int(data[0])
index = 1

for _ in range(T):
    X = int(data[index])
    index += 1
    
    if X <= 20:
        cost = X * 10
    else:
        cost = 20 * 10
        remaining_runs = X - 20
        balls_in_second_phase = remaining_runs // 2
        cost += balls_in_second_phase * 5
    
    print(cost)