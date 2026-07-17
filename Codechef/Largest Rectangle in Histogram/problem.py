def largestRectangleArea(N: int, A: list[int]) -> int:
    stack = []
    max_area = 0
    
    for i in range(N):

        while stack and A[stack[-1]] > A[i]:
            height = A[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        
        stack.append(i)
        
    while stack:
        height = A[stack.pop()]
        width = N if not stack else N - stack[-1] - 1
        max_area = max(max_area, height * width)
        
    return max_area