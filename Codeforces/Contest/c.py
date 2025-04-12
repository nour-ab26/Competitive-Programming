def unhappy_people():
    n = int(input())
    wealth = [int(x) for x in input().split()]
    wealth.sort()
    
    if n <= 1:
        return -1
    
    min_diff = float('inf')
    for i in range(n):
        for j in range(n // 2, n):  # <--- Changed this line
            max_wealth = wealth[j]
            min_wealth = wealth[i]
            diff = max_wealth - min_wealth
            min_diff = min(min_diff, diff)
    
    return min_diff

print(unhappy_people())