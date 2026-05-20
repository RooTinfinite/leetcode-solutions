class Solution:
    def manhattan(self, x1, y1, x2, y2):
        return abs(x1-x2) + abs(y1-y2)

    def bestTower(self, towers: List[List[int]], center: List[int], radius: int) -> List[int]:
        reachables = []
        x = 0
        y = 0
        maxqf = -1
        rcount = 0
        for tower in towers:
            if self.manhattan(tower[0], tower[1], center[0], center[1]) <= radius:
                reachables.append(tower)
                if tower[2] > maxqf:
                    maxqf = tower[2]
                    x = tower[0]
                    y = tower[1]
                elif tower[2] == maxqf:
                    x, y = min([x,y], tower[:2])
                rcount += 1
        if rcount == 0:
            return [-1, -1]
        return [x, y]
        