def solveNQueens(N: int) -> list[list[str]]:
    cols = set()
    pos_diag = set() 
    neg_diag = set()  
    
    result = []
    board = [["."] * N for _ in range(N)]
    
    def backtrack(r):
        if r == N:
            copy = ["".join(row) for row in board]
            result.append(copy)
            return
        
        for c in range(N):
            if c in cols or (r + c) in pos_diag or (r - c) in neg_diag:
                continue
                
            # Place the queen
            cols.add(c)
            pos_diag.add(r + c)
            neg_diag.add(r - c)
            board[r][c] = "Q"
            
            backtrack(r + 1)
            

            cols.remove(c)
            pos_diag.remove(r + c)
            neg_diag.remove(r - c)
            board[r][c] = "."

    backtrack(0)
    return result