class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        
        def distance(b1, b2):
            return sqrt((b1[0]-b2[0])*(b1[0]-b2[0]) + (b1[1]-b2[1])*(b1[1]-b2[1]))

        distanceMatrix = [[0]*len(bombs) for i in range(len(bombs))]

        n = len(bombs)

        for r in range(n):
            for c in range(n):
                distanceMatrix[r][c] = distance(bombs[r], bombs[c])

        
        self.maxExplosions = 0

        # print (distanceMatrix)

        for b in range(n):

            detonated = set()

            def numOfExplosions(b):
                detonated.add(b)

                for i in range(n):
                    if (distanceMatrix[b][i] <= float(bombs[b][2]) and (i not in detonated) and b != i):
                        numOfExplosions(i)
                
            numOfExplosions(b)

            self.maxExplosions = max(self.maxExplosions, len(detonated))

        return self.maxExplosions