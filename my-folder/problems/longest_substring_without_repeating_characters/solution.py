class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        ans = 0
        count = 0
        j = 0
        
        for i in range(0,len(s)):
            if s[i] not in dic:
                dic[s[i]] = 1
            else:
                dic[s[i]] = dic[s[i]]+1
            
            while dic[s[i]] > 1:
                dic[s[j]] = dic[s[j]] - 1
                j = j+1
                
            ans = max(ans, i-j+1)
            
        return ans