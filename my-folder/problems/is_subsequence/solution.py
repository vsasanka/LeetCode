class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        j = 0
        
        if (len(s) > len(t)):
            return False
        
        if (len(s) == 0):
            return True
        
        while i<len(s) and j < len(t):
            if (s[i] != t[j]):
                j += 1
            else:
                i += 1
                j += 1
            
        if (i != len(s)):
            return False
        
        return True