import sys
from typing import List
 
input = sys.stdin.read
data = input().split()
index = 0
multTestQ = int(data[index])
index += 1
 
answers = []
for _ in range(multTestQ):
    n = int(data[index])
    index += 1
    a = [int(data[index + i]) for i in range(n)]
    index += n
    b = [int(data[index + i]) for i in range(n)]
    index += n
 
    if n == 0:
        answers.append(0)
        continue
 
    any_pos: List[List[int]] = [[] for _ in range(n + 2)]
    match_pos: List[List[int]] = [[] for _ in range(n + 2)]
 
    for i in range(1, n + 1):
        aa = a[i - 1]
        bb = b[i - 1]
        any_pos[aa].append(i)
        any_pos[bb].append(i)
        if aa == bb:
            match_pos[aa].append(i)
 
    # unique any_pos
    for x in range(1, n + 2):
        if any_pos[x]:
            temp = []
            last = -1
            for pos in any_pos[x]:
                if pos != last:
                    temp.append(pos)
                    last = pos
            any_pos[x] = temp
 
    # k=0
    events = any_pos[1]
    tot = 0
    prev = 0
    for pos in events + [n + 1]:
        g = pos - prev - 1
        tot += g * (g + 1) // 2
        prev = pos
 
    # now positive
    starters = match_pos[1]
    if starters:
        current_groups = []
        i_any = 0
        prev_any = 0
        for p in starters:
            while i_any < len(any_pos[1]) and any_pos[1][i_any] < p:
                prev_any = any_pos[1][i_any]
                i_any += 1
            left_cnt = p - prev_any
            current_groups.append((p, left_cnt))
 
        x = 1
        while current_groups and x <= n:
            # add contrib for exactly this x
            next_any_l = any_pos[x + 1]
            ptr = 0
            for p, mult in current_groups:
                while ptr < len(next_any_l) and next_any_l[ptr] <= p:
                    ptr += 1
                if ptr < len(next_any_l):
                    nextp = next_any_l[ptr]
                    num_r = nextp - p
                else:
                    num_r = n - p + 1
                tot += mult * num_r
 
            # prepare next_groups
            next_groups = []
            next_any_l = any_pos[x + 1]
            ptr_any = 0
            for p_prev, mult in current_groups:
                while ptr_any < len(next_any_l) and next_any_l[ptr_any] <= p_prev:
                    ptr_any += 1
                if ptr_any >= len(next_any_l):
                    continue
                next_p = next_any_l[ptr_any]
                # check match
                if a[next_p - 1] == b[next_p - 1] == x + 1:
                    if not next_groups or next_groups[-1][0] != next_p:
                        next_groups.append([next_p, mult])
                    else:
                        next_groups[-1][1] += mult
            current_groups = next_groups
            x += 1
 
    answers.append(tot)
 
for ans in answers:
    print(ans)