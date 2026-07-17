import sys

input = sys.stdin.read
data = input().split()

T = int(data[0])
index = 1

for _ in range(T):
    N = int(data[index])
    K = int(data[index + 1])
    index += 2

    cards = list(range(K, 0, -1))
    player_decks = [0] * (N + 1)
    
    pick_index = 0
    direction = 1  
    while pick_index < K:
        if direction == 1:
            for p in range(1, N + 1):
                if pick_index < K:
                    player_decks[p] += cards[pick_index]
                    pick_index += 1
        else:
            for p in range(N, 0, -1):
                if pick_index < K:
                    player_decks[p] += cards[pick_index]
                    pick_index += 1
        direction = -direction
    
    max_strength = max(player_decks[1:])
    print(max_strength)
    