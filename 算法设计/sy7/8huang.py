def solve_n_queens(n):
    solutions = []  # 存储所有的解
    board = [-1] * n  # board[i]表示第i行皇后的列位置，初始化为-1，表示没有放置

    def is_safe(row, col):
        # 检查当前位置 (row, col) 是否安全放置皇后
        for i in range(row):
            # 检查同列是否有皇后或对角线上是否有皇后
            if board[i] == col or abs(board[i] - col) == abs(i - row):
                return False
        return True

    def backtrack(row):
        if row == n:
            # 找到一个解，将其转换成题目要求的格式
            solution = []
            for i in range(n):
                # 将行和列的位置从0-based转换为1-based
                solution.append((i + 1, board[i] + 1))
            solutions.append(solution)
        else:
            for col in range(n):
                if is_safe(row, col):
                    board[row] = col  # 在当前行放置皇后
                    backtrack(row + 1)  # 递归到下一行
                    board[row] = -1  # 回溯，撤销当前行的皇后

    backtrack(0)  # 从第0行开始
    return solutions

# 示例输入
n = int(input())
solutions = solve_n_queens(n)

# 输出格式化
for i, solution in enumerate(solutions):
    print(f"第{i + 1}个解: " + " ".join(f"({x},{y})" for x, y in solution))
