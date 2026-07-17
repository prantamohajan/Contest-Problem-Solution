def countDistinctInSubmatrix(N: int, A: list[list[int]], Q: int, queries: list[list[int]]) -> list[int]:
    pref = [[[0] * (N + 1) for _ in range(N + 1)] for _ in range(11)]
    
    for k in range(1, 11):
        for i in range(1, N + 1):
            for j in range(1, N + 1):
                val = 1 if A[i-1][j-1] == k else 0
                pref[k][i][j] = (val + 
                                 pref[k][i-1][j] + 
                                 pref[k][i][j-1] - 
                                 pref[k][i-1][j-1])
    
    results = []
    for X1, Y1, X2, Y2 in queries:
        distinct_count = 0
        for k in range(1, 11):
            count_k = (pref[k][X2][Y2] - 
                       pref[k][X1-1][Y2] - 
                       pref[k][X2][Y1-1] + 
                       pref[k][X1-1][Y1-1])
            if count_k > 0:
                distinct_count += 1
        results.append(distinct_count)
        
    return results