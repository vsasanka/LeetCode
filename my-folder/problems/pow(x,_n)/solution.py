class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(x, n):
            if x == 0: return 0
            if n == 0: return 1

            res = helper(x, n // 2)
            res = res*res

            if n % 2:
                res = res*x

            return res

        ans = helper(x, abs(n))

        if n < 0:
            return 1/ans
        return ans