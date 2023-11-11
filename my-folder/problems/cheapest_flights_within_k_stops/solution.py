class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prices = [float("inf") for _ in range(n)]

        prices[src] = 0

        for i in range(k+1):
            tmpPrices = prices.copy()

            for s, d, p in flights:
                if (prices[s] == float("inf")):
                    continue
                tmpPrices[d] = min(tmpPrices[d], prices[s] + p)
            
            prices = tmpPrices
        
        if prices[dst] == float("inf"):
            return -1
        return prices[dst]