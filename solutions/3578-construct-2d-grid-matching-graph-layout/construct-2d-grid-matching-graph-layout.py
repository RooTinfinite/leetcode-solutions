class Solution:
    def constructGridLayout(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        #bloated code but it is what it is
        adjList = [set() for _ in range(n)]

        for u, v in edges:
            adjList[u].add(v)
            adjList[v].add(u)
        
        oner = -1
        corner = -1
        for i in range(n):
            if len(adjList[i]) == 1:
                oner = i
            if len(adjList[i]) == 2:
                corner = i

        #one row edge case
        if oner >= 0:
            ans = [oner]
            ansSet = set(ans)
            while len(ans) < n:
                lastNum = ans[-1]
                for nextNum in adjList[lastNum]:
                    if nextNum not in ansSet:
                        ansSet.add(nextNum)
                        ans.append(nextNum)
            return [ans]

        def unused(node, added):
            ans = []
            for n in adjList[node]:
                if n not in added:
                    ans.append(n)
            return ans

        def shared(node1, node2, added):
            for n in adjList[node1]:
                if n in adjList[node2] and n not in added:
                    return n
            return -1

        
        ans = []
        firstNeighbors = list(adjList[corner])
        currRow = [corner, firstNeighbors[0]]
        nextRow = [firstNeighbors[1]]
        added = set([corner, firstNeighbors[0], firstNeighbors[1]])
        #build first 2 rows
        while len(nextRow) < len(currRow):
            top = currRow[-1]
            bottom = nextRow[-1]
            nextBot = shared(top, bottom, added)
            added.add(nextBot)
            nextRow.append(nextBot)
            nextTop = unused(top, added)
            if len(nextTop) == 1:
                nextTop = nextTop[0]
                added.add(nextTop)
                currRow.append(nextTop)
        ans = [currRow, nextRow]

        #build everything else
        while len(added) < n:
            newRow = []
            prevRow = ans[-1]
            for i in range(len(prevRow)):
                nextVal = unused(prevRow[i], added)[0]
                added.add(nextVal)
                newRow.append(nextVal)
            ans.append(newRow)
        return ans