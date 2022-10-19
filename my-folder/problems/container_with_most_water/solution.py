class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        
        watermax = 0
        
        while i<j:
            water = min(height[i], height[j])*(j-i)
            watermax = max(watermax, water)
            
            if height[i] < height[j]:
                i = i+1
            else:
                j = j - 1
        
        return watermax