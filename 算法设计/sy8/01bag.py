def knapsack(n, weights, values, capacity):
    class Item:
        def __init__(self, weight, value):
            self.weight = weight
            self.value = value
            self.unit_value = value / weight

    items = [Item(weights[i], values[i]) for i in range(n)]
    items.sort(key=lambda x: x.unit_value, reverse=True)

    max_value = 0
    selected_items = [0] * n
    remaining_capacity = capacity

    def bound(k, current_value, current_weight):
        if current_weight >= capacity:
            return 0
        else:
            bound_value = current_value
            remaining_weight = remaining_capacity - current_weight
            j = k + 1
            while j < n and items[j].weight <= remaining_weight:
                bound_value += items[j].value
                remaining_weight -= items[j].weight
                j += 1
            if j < n:
                bound_value += items[j].unit_value * remaining_weight
            return bound_value

    def knapsack_recursive(k, current_value, current_weight):
        nonlocal max_value, selected_items, remaining_capacity

        if current_weight <= capacity and current_value > max_value:
            max_value = current_value
            selected_items = [1 if i in range(k) else 0 for i in range(n)]
            remaining_capacity = capacity - current_weight

        if k >= n:
            return

        if current_weight + items[k].weight <= capacity:
            knapsack_recursive(k + 1, current_value + items[k].value, current_weight + items[k].weight)

        if bound(k, current_value, current_weight) > max_value:
            knapsack_recursive(k + 1, current_value, current_weight)

    knapsack_recursive(0, 0, 0)

    return max_value, selected_items

n = int(input())
weights = list(map(int, input().split()))
values = list(map(int, input().split()))
capacity = int(input())

max_value, selected_items = knapsack(n, weights, values, capacity)

print(max_value)
print(" ".join(str(i+1) for i in range(n) if selected_items[i] == 1))
