class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        pre1 = [0 for _ in range(n+1)]
        pre2 = [0 for _ in range(n+1)]

        for i in range(1, n + 1):
            if customers[i-1] == 'N':
                pre1[i] = pre1[i-1] + 1
            else:
                pre1[i] = pre1[i-1]

        ans = pre1[n] + pre2[n]
        ans_index = n

        for i in range(n-1, -1, -1):
            if customers[i] == 'Y':
                pre2[i] = pre2[i+1] + 1
            else:
                pre2[i] = pre2[i+1]
            if ans >= pre1[i] + pre2[i]:
                ans = pre1[i] + pre2[i]
                ans_index = i

        return ans_index
            