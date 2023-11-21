class Solution:
    def smallestNumber(self, num: int) -> int:
        negative = False

        if num < 0:
            num = abs(num)
            negative = True
        
        num = str(num)

        num = sorted(num, reverse=negative)

        zeros = 0

        while len(num) > 1 and num[0] == '0':
            num = num[1:]
            zeros += 1

        if num[0] == '0':
            return 0

        # print (num)

        num = str(num[0]) + "0"*zeros + ("".join(num[1:]) if len(num) > 1 else "")

        return int(num)*(-1 if negative else 1)