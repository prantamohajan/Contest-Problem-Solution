def hasPairWithDifference(A: list[int], N: int, B: int) -> int:
    seen = set(A)
    for x in A:
        if (x + B) in seen and (B != 0 or A.count(x) > 1):
            return 1
    return 0