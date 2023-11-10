class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        graph = [[0]*n for _ in range(n)]

        def manDistance(p1, p2):
            return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1])

        for i in range(n):
            for j in range(n):
                graph[i][j] = manDistance(i,j)

        minH = [[0,0]]

        heapq.heapify(minH)
        cost = 0
        visited = set()

        while len(visited) < n:
            c, point = heapq.heappop(minH)

            if point in visited:
                continue

            visited.add(point)
            cost += c

            for i in range(n):
                if i != point and i not in visited:
                    heapq.heappush(minH, [graph[point][i], i])

        return cost