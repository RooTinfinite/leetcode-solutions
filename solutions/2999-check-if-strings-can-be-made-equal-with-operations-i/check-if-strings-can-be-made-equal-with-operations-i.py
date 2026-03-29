class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        odd, even = defaultdict(int), defaultdict(int)
        for i in range(len(s1)):
            if i % 2 == 0:
                even[s1[i]] += 1
                even[s2[i]] -= 1
            else:
                odd[s1[i]] += 1
                odd[s2[i]] -= 1

        return set(odd.values()) == {0} and set(even.values()) == {0}