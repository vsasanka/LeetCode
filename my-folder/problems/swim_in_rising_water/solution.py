class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        minH = [[grid[0][0], 0, 0]]
        heapq.heapify(minH)
        directions = [[0,1],[1,0],[0,-1],[-1,0]]
        visited = set()

        N = len(grid)
        visited.add((0,0))

        while True:
            t, r, c = heapq.heappop(minH)

            if r == N - 1 and c == N - 1:
                return t
            
            for nei in directions:
                nR = r + nei[0]
                nC = c + nei[1]

                if nR < 0 or nC < 0 or nR == N or nC == N or (nR,nC) in visited:
                    continue
                
                heapq.heappush(minH, [max(t, grid[nR][nC]), nR, nC])
                visited.add((nR,nC))