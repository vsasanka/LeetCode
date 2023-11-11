class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        first = 0
        second = 0

        for i in range(2, len(cost)+1):
            present = min(first + cost[i-2], second + cost[i-1])
            first = second
            second = present
        
        return second
