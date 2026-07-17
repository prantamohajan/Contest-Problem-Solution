def findMinPlatforms(AT: list[int], DT: list[int], n: int) -> int:
    AT.sort()
    DT.sort()
    platforms = max_platforms = 1
    i = j = 0
    i += 1
    while i < n and j < n:
        if AT[i] <= DT[j]:
            platforms += 1
            i += 1
        else:
            platforms -= 1
            j += 1
        max_platforms = max(max_platforms, platforms)
    return max_platforms