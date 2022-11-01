class Solution:
    def recursion(self, row, col, grid, lastState):
        
        if col >= self.cols or col < 0:
            return -1
        
        if row == self.rows:
            return col
        
        if self.visited[lastState][row][col] == True:
            return self.dp[lastState][row][col]
        
        self.visited[lastState][row][col] == True
        
        if lastState == 0:
            self.dp[lastState][row][col] = self.recursion(row, col+grid[row][col], grid, grid[row][col])
        elif lastState == grid[row][col]:
            self.dp[lastState][row][col] = self.recursion(row+1, col, grid, 0)
        else:
            self.dp[lastState][row][col] = -1
            
        return self.dp[lastState][row][col]
    
    def findBall(self, grid: List[List[int]]) -> List[int]:
        self.dp = [[[-1 for _ in range(len(grid[0]))] for i in range(len(grid))] for j in range(3)]
        
        self.visited = [[[False for _ in range(len(grid[0]))] for i in range(len(grid))] for j in range(3)]
        
        self.rows = len(grid)
        self.cols = len(grid[0])
        
        answer = []
        
        for i in range(self.cols):
            answer.append(self.recursion(0,i, grid, 0))
            
        return answer
            
        
        
        
        