class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        preRow1, preRow2 = grid[0].copy(), grid[1].copy()

        for i in range(1, len(grid[0])):
            preRow1[i] += preRow1[i-1]
            preRow2[i] += preRow2[i-1]

        res = float("inf")

        for i in range(len(grid[0])):
            top = preRow1[-1] - preRow1[i]
            buttom = preRow2[i] - grid[1][i]

            second = max(top, buttom)
            res = min(res, second)

        return res