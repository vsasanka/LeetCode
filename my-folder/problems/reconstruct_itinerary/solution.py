class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        targets = defaultdict(list)

        tickets.sort()
        
        for a, b in tickets[::-1]:
            targets[a].append(b)

        route = []
        
        def visit(airport):
            while targets[airport]:
                visit(targets[airport].pop())
            route.append(airport)
        visit('JFK')
        return route[::-1]