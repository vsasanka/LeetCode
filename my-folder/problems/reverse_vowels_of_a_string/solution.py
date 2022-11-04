class Solution:
    def reverseVowels(self, s: str) -> str:
        
        stack = []
        
        for c in s:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U':
                stack.append(c)
        
        for i in range(len(s)):
            c = s[i]
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U':
                s = s[:i] + stack.pop() + s[i+1:]
                # stack.pop()
                
        return s