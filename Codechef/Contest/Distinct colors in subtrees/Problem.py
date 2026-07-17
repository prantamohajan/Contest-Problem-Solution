def distinctColorsInSubtrees(N: int, C: list[int], edges: list[list[int]]) -> list[int]:
    from collections import defaultdict
    adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    result = [0] * (N + 1)
    color_sets = [None] * (N + 1)

    parent = [0] * (N + 1)
    order = []
    visited = [False] * (N + 1)
    stack = [1]
    visited[1] = True
    parent[1] = -1
    
    while stack:
        node = stack.pop()
        order.append(node)
        for nb in adj[node]:
            if not visited[nb]:
                visited[nb] = True
                parent[nb] = node
                stack.append(nb)
    
    for node in reversed(order):
        color_sets[node] = {C[node - 1]}
        for nb in adj[node]:
            if nb != parent[node]:
                # Small-to-large merge
                if len(color_sets[nb]) > len(color_sets[node]):
                    color_sets[node], color_sets[nb] = color_sets[nb], color_sets[node]
                color_sets[node].update(color_sets[nb])
                color_sets[nb] = None
        result[node] = len(color_sets[node])
    
    return result[1:]