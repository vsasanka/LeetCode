class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        
        i,j = 0,0
        
        one_counter = 0
        
        ans = ""
        
        while j < len(s):
            while one_counter < k and j < len(s):
                if s[j] == '1':
                    one_counter = one_counter + 1
                j = j + 1
                
            while i < j:
                if s[i] == '0':
                    i = i + 1
                else:
                    break
                
            # print (one_counter)
            
            if (one_counter == k):
                new_string = s[i:j]
                # print (new_string)
                if ans == "":
                    ans = new_string
                elif len(new_string) < len(ans):
                    ans = new_string
                elif len(new_string) == len(ans) and new_string < ans:
                    ans = new_string
            
            while one_counter == k and i < j:
                if s[i] == '1':
                    one_counter = one_counter - 1
                i = i + 1
        
        return ans
                    
                    
                