class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        matrixSum = [[0]*(len(matrix[0])+1) for _ in range(len(matrix) + 1)]

        for i in range(1, len(matrixSum)):
            for j in range(1, len(matrixSum[0])):
                matrixSum[i][j] = matrixSum[i-1][j] + matrixSum[i][j-1] - matrixSum[i-1][j-1] + matrix[i-1][j-1]

        self.matrixSum = matrixSum

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.matrixSum[row2 + 1][col2 + 1] + self.matrixSum[row1][col1] - self.matrixSum[row2 + 1][col1] - self.matrixSum[row1][col2 + 1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)