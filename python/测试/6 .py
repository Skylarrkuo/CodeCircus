import sympy

# �������
x, y, z = symbols('x y z')

# ���巽��
eq1 = Eq(x + y + z, 100)
eq2 = Eq(5*x + 3*y + z/3, 100)

# �ⷽ����
solution = solve((eq1, eq2), (x, y, z))