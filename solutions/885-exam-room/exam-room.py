class ExamRoom:
    def __init__(self, n: int):
        self.occ = []
        self.heap = [(-n, 0)]
        self.n = n
        
    def seat(self) -> int:
        while self.heap:
            dist, pos = heappop(self.heap)
            i = bisect_left(self.occ, pos)
            if not self.occ: break
            if i == len(self.occ): nxt = None
            else: nxt = self.occ[i]
            if i == 0: prv = None
            else: prv = self.occ[i-1]
            # if nxt is None and prv is None: print("Not possible as len(self.occ) != 0")
            if nxt is None: nxt = 2*(self.n-1) - prv
            if prv is None: prv = -nxt
            d = (nxt - prv)//2
            if d == -dist: break

        if i != 0: prv = self.occ[i-1]
        else: prv = -pos
        d = (pos - prv)//2
        if d != 0:
            heappush(self.heap, (-d, pos-d))
            if pos-d != prv+d: heappush(self.heap, (-d, prv+d))
            
        if i != len(self.occ): nxt = self.occ[i]
        else: nxt = 2*(self.n-1) - pos
        d = (nxt - pos)//2
        if d != 0:
            heappush(self.heap, (-d, pos+d))
            if pos+d != nxt-d: heappush(self.heap, (-d, nxt-d))
        
        self.occ.insert(i, pos)
        return pos
    def leave(self, p: int) -> None:
        if len(self.occ) == 1:
            self.heap = [(-self.n, 0)]
            self.occ.clear()
            return
            
        i = bisect_left(self.occ, p)
        if i == len(self.occ)-1: nxt = None
        else: nxt = self.occ[i+1]
        if i == 0: prv = None
        else: prv = self.occ[i-1]
        # if nxt is None and prv is None: print("Not possible as len(self.occ) != 1")
        if nxt is None: nxt = 2*(self.n-1) - prv
        if prv is None: prv = -nxt
        
        d = (nxt - prv)//2
        heappush(self.heap, (-d, nxt-d))
        if prv+d != nxt-d: heappush(self.heap, (-d, prv+d))
        
        del self.occ[i]