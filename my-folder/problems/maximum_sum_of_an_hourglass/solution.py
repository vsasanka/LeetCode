class Solution(object):
    
    def maxSum(self, grid):
        """
        
        :type grid: List[List[int]]
        :rtype: int
        """
        def hg(i,j,grid):
            ans = 0;
            for a in range(j,j+3):
                ans = ans + grid[i][a]
            for a in range(j,j+3):
                ans = ans + grid[i+2][a]
            ans = ans + grid[i+1][j+1]

            return ans
    
        maxv = 0;
        for i in range(0, len(grid) - 2):
            for j in range(0,len(grid[0]) - 2):
                maxv = max(maxv, hg(i,j, grid))
                
        return maxv
        