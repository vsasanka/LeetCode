class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = {}

        def dfs(r, c, prev):
            if r < 0 or r == m or c < 0 or c == n or prev >= matrix[r][c]:
                return 0
            if (r, c) in dp:
                return dp[(r, c)]

            res = 1
            res = max(res, 1 + dfs(r + 1, c, matrix[r][c]))
            res = max(res, 1 + dfs(r - 1, c, matrix[r][c]))
            res = max(res, 1 + dfs(r, c + 1, matrix[r][c]))
            res = max(res, 1 + dfs(r, c - 1, matrix[r][c]))

            dp[(r, c)] = res
            return res
        
        ans = 1

        for r in range(m):
            for c in range(n):
                ans = max(ans, dfs(r, c, -1))

        return ans
