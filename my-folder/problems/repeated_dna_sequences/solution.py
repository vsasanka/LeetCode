class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen, res = set(), set()

        for i in range(len(s) - 9):
            ss = s[i:i+10]

            if ss in seen:
                res.add(ss)
            seen.add(ss)

        return list(res)