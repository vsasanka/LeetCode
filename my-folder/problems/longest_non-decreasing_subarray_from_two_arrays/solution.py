class Solution:
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:

        n = len(nums1)

        dp = [[1]*n for _ in range(2)]

        sol = 1

        for i in range(1, n):
            if (nums1[i] >= nums1[i-1]):
                if i == 2: print (1)
                dp[0][i] = max(dp[0][i], 1 + dp[0][i-1])
                
            if nums1[i] >= nums2[i-1]:
                if i == 2: print (2)
                dp[0][i] = max(dp[0][i], 1 + dp[1][i-1])
                
            if (nums2[i] >= nums1[i-1]):
                if i == 2: print (3)
                dp[1][i] = max(dp[1][i], 1 + dp[0][i-1])
                
            if nums2[i] >= nums2[i-1]:
                if i == 2: print (4)
                dp[1][i] = max(dp[1][i], 1 + dp[1][i-1])
                
            sol = max(sol, max(dp[0][i], dp[1][i]))

        print (dp)
            
        return sol