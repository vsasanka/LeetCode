class DetectSquares:

    def __init__(self):
        self.pointsFreq = defaultdict(int)
        self.pointsList = []

    def add(self, point: List[int]) -> None:
        self.pointsFreq[(point[0], point[1])] += 1
        self.pointsList.append(point)

    def count(self, point: List[int]) -> int:
        res = 0
        x, y = point

        for px, py in self.pointsList:
            if abs(px - x) != abs(py - y) or px == x or py == y:
                continue
            res += self.pointsFreq[(px, y)] * self.pointsFreq[(x,py)]

        return res


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)