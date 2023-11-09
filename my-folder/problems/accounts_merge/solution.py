class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        
        parent = [i for i in range(n)]
        rank = [1 for i in range(n)]
        
        def find(p):
            while p != parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]

            return p
        
        def union(a1, a2):
            p1, p2 = find(a1), find(a2)

            if rank[p1] > rank[p2]:
                parent[p2] = p1
                rank[p1] += rank[p2]
            else:
                parent[p1] = p2
                rank[p2] += rank[p1]

        emailParentMap = dict()

        for i in range(n):
            for j in range(1, len(accounts[i])):
                email = accounts[i][j]
                
                if email in emailParentMap.keys():
                    parentOfAccount = find(i)
                    parentOfEmail = emailParentMap[email]
                    union(parentOfEmail, parentOfAccount)
                else:
                    emailParentMap[email] = find(i)
            # print (emailParentMap)
            # print (parent)

        for i in range(n):
            parent[i] = find(i)

        ans = [set() for _ in range(n)]

        for i in range(n):
            for j in range(1, len(accounts[i])):
                ans[parent[i]].add(accounts[i][j])

        ansFinal = []

        for i in range(n):
            if (len(ans[i]) != 0):
                ansFinal.append(list(ans[i]))
                ansFinal[len(ansFinal) - 1].sort()
                ansFinal[len(ansFinal) - 1].insert(0, accounts[i][0])

        return ansFinal


