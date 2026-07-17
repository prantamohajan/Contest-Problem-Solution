import sys
from collections import Counter

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

for _ in range(T):
    N = int(data[index])
    X = int(data[index + 1])
    K = int(data[index + 2])
    index += 3
    
    scores = []
    for i in range(N):
        scores.append(int(data[index]))
        index += 1
    
    # Count frequency of each score
    freq = Counter(scores)
    
    # Sort scores in descending order
    sorted_scores = sorted(freq.keys(), reverse=True)
    
    # Take top K clusters
    total = 0
    for i in range(min(K, len(sorted_scores))):
        total += freq[sorted_scores[i]]
    
    # Maximum we can select is min(total eligible, X)
    result = min(total, X)
    print(result)