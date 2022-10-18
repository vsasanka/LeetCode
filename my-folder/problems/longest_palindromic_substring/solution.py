class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        def isPal(i: int, j: int):
            while (i>=0 and j<len(s) and s[i] == s[j]):
                i = i - 1
                j = j + 1
                
            return s[i+1:j:1]
        
        ans = ""
        s1 = ""
        s2 = ""
        
        # print(isPal(1,1))
        
        for i in range(0,len(s)):
            s1 = isPal(i,i)
            s2 = isPal(i,i+1)
            
            if len(s1) > len(ans):
                ans = s1
            if len(s2) > len(ans):
                ans = s2
                
        return ans