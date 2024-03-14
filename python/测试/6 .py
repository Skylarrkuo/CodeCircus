import sympy

# 定义变量
x, y, z = symbols('x y z')

# 定义方程
eq1 = Eq(x + y + z, 100)
eq2 = Eq(5*x + 3*y + z/3, 100)

# 解方程组
solution = solve((eq1, eq2), (x, y, z))