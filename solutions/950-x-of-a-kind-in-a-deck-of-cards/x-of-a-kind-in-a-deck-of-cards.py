from functools import reduce
from math import gcd
from collections import Counter

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        return reduce(gcd,Counter(deck).values()) != 1
		
