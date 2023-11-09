class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [False for i in range(len(isConnected))]
        n = len(isConnected)

        numProvince = 0

        for i in range(n):

            def travel(i):
                visited[i] = True

                for j in range(n):
                    if (isConnected[i][j] == 1 and visited[j] == False):
                        travel(j)

            if (visited[i] == False):
                numProvince += 1
                travel(i)

        return numProvince