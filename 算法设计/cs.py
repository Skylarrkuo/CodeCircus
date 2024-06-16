import heapq

def shortest_path(edges, source):
    # 创建图的邻接表表示
    graph = {}
    for edge in edges:
        if edge[0] not in graph:
            graph[edge[0]] = []
        graph[edge[0]].append((edge[1], edge[2]))

    # 初始化优先队列
    queue = [(0, source, [source])]  # (cost, vertex, path)
    visited = set()

    # 存储最短路径结果
    paths = {}

    while queue:
        cost, vertex, path = heapq.heappop(queue)
        if vertex not in visited:
            visited.add(vertex)
            paths[vertex] = (cost, path)

            for next_vertex, weight in graph.get(vertex, []):
                if next_vertex not in visited:
                    heapq.heappush(queue, (cost + weight, next_vertex, path + [next_vertex]))

    return paths

# 输入的边
edges = [
    (0, 2, 10),
    (0, 4, 30),
    (0, 5, 100),
    (1, 2, 4),
    (2, 3, 50),
    (3, 5, 10),
    (4, 3, 20),
    (4, 5, 60)
]

# 源点
source = 0

# 计算最短路径
paths = shortest_path(edges, source)

# 输出结果
for vertex in range(len(edges)):
    if vertex in paths:
        print(f"从源点{source}到顶点{vertex}的最短路径长度:{paths[vertex][0]}，路径：{' '.join(map(str, paths[vertex][1]))}")
    else:
        print(f"从源点{source}到顶点{vertex}没有路径")
