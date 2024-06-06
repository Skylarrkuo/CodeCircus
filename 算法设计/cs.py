def is_prime(num):
    """判断一个数是否为素数"""
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def print_ring(ring):
    """打印素数环"""
    print(" ".join(map(str, ring)))

def backtracking(n, ring, used, index):
    """
    回溯函数,用于构建素数环

    参数:
    n: 环的大小
    ring: 当前构建的环
    used: 标记哪些数字已经被使用
    index: 当前需要填充的位置
    """
    if index == n:
        # 如果已经填满环,检查首尾和是否为素数
        if is_prime(ring[0] + ring[n-1]):
            print_ring(ring)
    else:
        for i in range(2, n + 1):
            if not used[i]:
                # 如果数字i未被使用且与前一个数字之和为素数
                if is_prime(i + ring[index-1]):
                    ring[index] = i
                    used[i] = True
                    backtracking(n, ring, used, index + 1)
                    used[i] = False

"""主函数,读取输入并寻找素数环"""
while True:
    n = int(input())
    if n == 0:
        break
        
    ring = [0] * n  # 初始化环
    used = [False] * (n + 1)  # 初始化使用标记数组
    ring[0] = 1  # 环的第一个位置固定为1
    used[1] = True  # 标记1已经被使用
        
    print(f"{n}个数的素数环:")
        
    # 如果n为奇数且大于1,则直接输出"No Circle"
    if n > 1 and n % 2 == 1:
        print("No Circle")
    else:
        backtracking(n, ring, used, 1)

"""
算法: 寻找素数环

输入: n - 素数环的大小

输出: 所有满足条件的素数环

初始化环和使用标记数组
将环的第一个位置固定为1,标记1已经被使用
如果n为奇数且大于1,则直接输出"No Circle"
否则,调用回溯函数backtracking(n, ring, used, 1)
4.1 如果当前位置为环的最后一个位置
4.1.1 如果已经填满环,检查首尾和是否为素数,如果是素数,则打印环
4.2 否则,遍历数字i从2到n+1
4.2.1 如果数字i未被使用且与前一个数字之和为素数
4.2.1.1 将数字i放入环的当前位置
4.2.1.2 标记数字i已经被使用
4.2.1.3 递归调用backtracking函数,当前位置索引加1
4.2.1.4 恢复数字i的使用状态
"""