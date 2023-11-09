class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        ones = [[0]*len(matrix[0]) for i in range(len(matrix))]
        
        for c in range(len(matrix[0])):
            dp = 0
            for r in range(len(matrix)):
                if matrix[r][c] == 1:
                    dp += 1
                else:
                    dp = 0
                ones[r][c] = dp

        ans = 0

        for r in range(len(matrix)):
            row = ones[r]
            row.sort(reverse=True)

            temp = 0
            
            for c in range(len(row)):
                temp = max(temp, row[c]*(c+1))
            ans = max(temp, ans)

        return ans