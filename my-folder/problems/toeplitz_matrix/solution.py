class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        
        def sameElements(row, col) -> bool:
            
            temp = matrix[row][col]
            
            # print ('Temp -> ' + str(temp))
            
            while row < rows and col < cols:
                # print (matrix[row][col])
                if (matrix[row][col] != temp):
                    return False
                row += 1
                col += 1
                
            return True
        
        rows = len(matrix)
        # print (rows)
        cols = len(matrix[0])
        
        for i in range(rows - 1, 0, -1):
            # print (i)
            if (sameElements(i,0) == False):
                return False
        
        for i in range(0, cols):
            if (sameElements(0,i) == False):
                return False
            
        return True
        
        