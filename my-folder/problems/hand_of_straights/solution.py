class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False

        count = {}

        for i in hand:
            count[i] = 1 + count.get(i, 0)

        minH = list(count.keys())
        heapq.heapify(minH)

        while minH:
            first = minH[0]

            for n in range(first, first + groupSize):
                if n not in minH:
                    return False
                count[n] -= 1

                if count[n] == 0:
                    if n != minH[0]:
                        return False
                    heapq.heappop(minH)
        return True