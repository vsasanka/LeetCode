class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        sum_window = 0
        i,j = 0,0
        n = len(arr)
        ans = 0

        while j < n:
            while j - i + 1 <= k:
                sum_window += arr[j]
                j += 1
            
            if sum_window / k >= float(threshold):
                ans += 1
            
            sum_window -= arr[i]
            i += 1

        return ans