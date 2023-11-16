class Solution:
    def checkValidString(self, s: str) -> bool:
        leftMin = 0
        leftMax = 0

        for p in s:
            if p == '(':
                leftMin, leftMax = leftMin + 1, leftMax + 1
            elif p == ')':
                leftMin, leftMax = leftMin - 1, leftMax - 1
            else:
                leftMax = leftMax + 1
                leftMin = leftMin - 1
            
            if leftMin < 0:
                leftMin = 0
            
            if leftMax < 0:
                return False
        
        return leftMin == 0