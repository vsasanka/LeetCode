class UndergroundSystem:

    def __init__(self):
        self.start_map = {}
        self.start_stop_map = {}


    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.start_map[id] = [stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_stop = (self.start_map[id][0], stationName)
        time_duration = t - self.start_map[id][1]

        if start_stop not in self.start_stop_map:
            self.start_stop_map[start_stop] = []
            
        self.start_stop_map[start_stop].append(time_duration)


    def getAverageTime(self, startStation: str, endStation: str) -> float:
        t = 0
        for time in self.start_stop_map[(startStation, endStation)]:
            t += time
        return t / len(self.start_stop_map[(startStation, endStation)])


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)