class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for i in range(0,len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stack.append(s[i])
            elif s[i] == ']' and (len(stack) == 0 or stack.pop() != '['):
                return False
            elif s[i] == '}' and (len(stack) == 0 or stack.pop() != '{'):
                return False
            elif s[i] == ')' and (len(stack) == 0 or stack.pop() != '('):
                return False
            
        if len(stack) != 0:
            return False
        
        return True