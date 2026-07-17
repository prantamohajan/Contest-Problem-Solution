class Solution:
    def kthAncestor(self, n, edges, v, k):
        from collections import defaultdict, deque
        
        adj = defaultdict(list)
        for u, w in edges:
            adj[u].append(w)
            adj[w].append(u)
        
        parent = {1: -1}
        queue = deque([1])
        visited = {1}
        while queue:
            node = queue.popleft()
            for nb in adj[node]:
                if nb not in visited:
                    visited.add(nb)
                    parent[nb] = node
                    queue.append(nb)
        
        cur = v
        for _ in range(k):
            cur = parent.get(cur, -1)
            if cur == -1:
                return -1
        return cur