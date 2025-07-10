class Bitset:
    def __init__(self, size: int):
        self.l = [0] * size
        self.ones = 0
        self.flipp = False
    
    def fix(self, idx: int) -> None:
        if self.flipp:
            if self.l[idx] == 1: self.ones += 1
            self.l[idx] = 0
        else:
            if self.l[idx] == 0: self.ones += 1
            self.l[idx] = 1
    
    def unfix(self, idx: int) -> None:
        if self.flipp:
            if self.l[idx] == 0: self.ones -= 1
            self.l[idx] = 1
        else: 
            if self.l[idx] == 1: self.ones -= 1
            self.l[idx] = 0
    
    def flip(self) -> None:
        self.flipp = not self.flipp
        self.ones = len(self.l) - self.ones
    
    def all(self) -> bool: return self.ones == len(self.l)
    def one(self) -> bool: return self.ones > 0 
    def count(self) -> int: return self.ones
    def toString(self) -> str: 
        return ''.join([str(0 if i else 1) for i in self.l]) if self.flipp else ''.join([str(i) for i in self.l])