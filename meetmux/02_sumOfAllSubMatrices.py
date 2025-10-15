def sum_of_all_submatrices(matrix):
    n = len(matrix)
    m = len(matrix[0])
    total = 0
    
    for i in range(n):
        for j in range(m):
            top_left = (i + 1) * (j + 1)
            bottom_right = (n - i) * (m - j)
            total += matrix[i][j] * top_left * bottom_right
    
    return total
    
n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

print(sum_of_all_submatrices(matrix))