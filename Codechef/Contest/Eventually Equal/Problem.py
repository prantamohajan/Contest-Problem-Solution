# cook your dish here
import sys
import math

def solve():
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return
    
    T = int(data[0])
    results = []
    idx = 1
    for _ in range(T):
        A = int(data[idx])
        B = int(data[idx+1])
        C = int(data[idx+2])
        idx += 3
    
        if A == B:
            results.append("0")
        elif math.gcd(A, C) == math.gcd(B, C):
            results.append("1")
        elif math.gcd(A, C + 1) == math.gcd(B, C + 1):
            results.append("2")
        else:
            results.append("3")
            
    print('\n'.join(results))

if __name__ == '__main__':
    solve()