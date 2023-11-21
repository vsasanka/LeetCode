class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        q = deque()
        dom = list(dominoes)

        for i in range(len(dom)):
            if (dom[i] == 'L' or dom[i] == 'R'):
                q.append((i, dom[i]))

        while q:
            i, d = q.popleft()

            if d == 'L':
                if i - 1 >= 0 and dom[i - 1] == '.':
                    dom[i - 1] = 'L'
                    q.append((i - 1, 'L'))
            else:
                if i + 1 < len(dom) and dom[i + 1] == '.':
                    if i + 2 < len(dom) and dom[i + 2] == 'L':
                        q.popleft()
                    else:
                        dom[i + 1] = 'R'
                        q.append((i + 1, 'R'))

        return "".join(dom)

            
