class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        
        binarySet = set()

        for i in range(len(s) - k + 1):
            binarySet.add(s[i:i+k])

        return len(binarySet) == 2 ** k