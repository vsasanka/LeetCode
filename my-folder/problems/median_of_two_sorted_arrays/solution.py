class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        small, large = nums1, nums2

        if (len(nums1) > len(nums2)):
            small, large = large, small

        total = len(small) + len(large)
        target = total // 2

        l, r = 0, len(small) - 1

        while True:
            m = (l + r) // 2

            p = target - m - 2

            Aleft = small[m] if m >= 0 else float('-infinity')
            Bleft = large[p] if p >= 0 else float('-infinity')
            Aright = small[m + 1] if m + 1 < len(small) else float('infinity') 
            Bright = large[p + 1] if p + 1 < len(large) else float('infinity')

            if Aleft <= Bright and Bleft <= Aright:
                if total % 2:
                    return min(Aright, Bright)
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            elif Aleft > Bright:
                r = m - 1
            else:
                l = m + 1
        
        return 0