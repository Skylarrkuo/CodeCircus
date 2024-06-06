def maxSubArray(nums):
    max_sum = float("-inf")  # 初始化最大子段和为负无穷
    current_sum = 0  # 初始化当前子段和为0
    start = 0  # 初始化最大子段和起始位置
    end = 0  # 初始化最大子段和结束位置
    s = 0  # 用于记录当前子段和的起始位置
    for i in range(len(nums)):
        current_sum += nums[i]  # 将当前数字加入当前子段和
        if current_sum > max_sum:  # 如果当前子段和大于最大子段和
            max_sum = current_sum  # 更新最大子段和
            start = s  # 更新最大子段和起始位置
            end = i  # 更新最大子段和结束位置
        if current_sum < 0:  # 如果当前子段和小于0
            current_sum = 0  # 重置当前子段和为0
            s = i + 1  # 更新当前子段和的起始位置
    return max_sum, nums[start : end + 1]  # 返回最大子段和以及最大子段

# 输入示例
N = int(input())
A = list(map(int, input().split()))

# 调用函数并输出结果
result, subarray = maxSubArray(A)
print(result)
print(" ".join(map(str, subarray)))
