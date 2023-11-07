class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])

        def areaOfIsland(r, c):
            if r == -1 or r == m or c == -1 or c == n or grid[r][c] == 0:
                return 0
            
            grid[r][c] = 0
            return 1 + areaOfIsland(r+1, c) + areaOfIsland(r-1, c) + areaOfIsland(r, c + 1) + areaOfIsland(r, c - 1)

        area = 0

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    area = max(area, areaOfIsland(r, c))

        return area
