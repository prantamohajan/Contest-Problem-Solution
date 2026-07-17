import sys
from collections import deque

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

def get_y(line, x):
    m, b = line
    return m * x + b

def bad(l1, l2, l3):
    m1, b1 = l1
    m2, b2 = l2
    m3, b3 = l3
    return (b3 - b1) * (m1 - m2) <= (b2 - b1) * (m1 - m3)

def add_line(deq, m, b):
    line = (m, b)
    while len(deq) >= 2 and bad(deq[-2], deq[-1], line):
        deq.pop()
    deq.append(line)

def query_deq(deq, x):
    if not deq:
        return None
    while len(deq) >= 2 and get_y(deq[0], x) <= get_y(deq[1], x):
        deq.popleft()
    return get_y(deq[0], x)

for _ in range(T):
    N = int(data[index])
    X = int(data[index + 1])
    index += 2
    A = [int(data[index + i]) for i in range(N)]
    index += N
    S = data[index]
    index += 1
    
    # sort items
    items = sorted((A[i], 1 if S[i] == '1' else 0) for i in range(N))
    
    # group
    vals = []
    ons = []
    i = 0
    while i < N:
        curr = items[i][0]
        cnt = 0
        while i < N and items[i][0] == curr:
            cnt += items[i][1]
            i += 1
        vals.append(curr)
        ons.append(cnt)
    
    M = len(vals)
    pre = [0] * (M + 1)
    for k in range(M):
        pre[k + 1] = pre[k] + ons[k]
    
    total_on = pre[M]
    empty_profit = -X * total_on
    
    deq_has = deque()
    deq_no = deque()
    
    max_var = float('-inf')
    
    for j in range(M):
        vj = vals[j]
        # single
        base_single = vj * vj + X * ons[j]
        force_single = 0 if ons[j] > 0 else 1
        var_single = base_single - force_single * X
        max_var = max(max_var, var_single)
        
        # queries i < j
        hasR = ons[j] > 0
        xp = vj
        prej1 = pre[j + 1]
        
        qh = query_deq(deq_has, xp)
        if qh is not None:
            base_h = qh + X * prej1
            if hasR:
                prof = base_h
            else:
                prof = base_h - X
            max_var = max(max_var, prof)
        
        qn = query_deq(deq_no, xp)
        if qn is not None:
            base_n = qn + X * prej1
            if hasR:
                prof = base_n - X
            else:
                prof = base_n - 2 * X
            max_var = max(max_var, prof)
        
        # add current
        m_new = vj
        b_new = -X * pre[j]
        if ons[j] > 0:
            add_line(deq_has, m_new, b_new)
        else:
            add_line(deq_no, m_new, b_new)
    
    # final answer
    if max_var == float('-inf'):
        answer = empty_profit
    else:
        answer = max(empty_profit, max_var - X * total_on)
    
    print(answer)