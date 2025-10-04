from typing import List
from collections import defaultdict

MOD = 10**9 + 7
RM = (MOD + 1) // 2

def mul(x, y):
    return x * y % MOD

def sqr(x):
    return mul(x, x)

def add(x, y):
    x += y
    if x >= MOD:
        x -= MOD
    return x

def sub(x, y):
    x -= y
    if x < 0:
        x += MOD
    return x

def C2(n):
    return mul(mul(n, n - 1), RM)

def count(v: List[int], c: List[int], countIfEqual: bool) -> int:
    n, m = len(v), len(c)
    t = [0] * m
    r = R2 = 0
    for i in range(m):
        R2 = add(R2, sqr(c[i]))
    RT = R2T = 0
    for i in range(n):
        x = v[i]
        rx = c[x] - t[x]
        r2 = sub(R2, sqr(rx))
        rt = sub(RT, mul(rx, t[x]))
        r2t = sub(R2T, mul(sqr(rx), t[x]))
        p = n - i - rx
        sumt = i - t[x]
        temp = mul(sub(sqr(p), r2), sumt)
        temp = sub(temp, mul(mul(2, p), rt))
        temp = add(temp, mul(2, r2t))
        temp = mul(temp, mul(t[x], RM))
        r = add(r, temp)
        r = add(r, mul(C2(t[x]), C2(p)))
        rx -= 1
        r = add(r, mul(C2(t[x]), mul(rx, p)))
        if countIfEqual:
            r = add(r, mul(mul(t[x], sumt), mul(rx, p)))
            r = add(r, mul(C2(t[x]), C2(rx)))
        t[x] += 1
        R2 = add(r2, sqr(rx))
        RT = add(rt, mul(rx, t[x]))
        R2T = add(r2t, mul(sqr(rx), t[x]))
    return r

class Solution:
    def subsequencesWithMiddleMode(self, nums: List[int]) -> int:
        mp = {}
        m = 0
        for i in range(len(nums)):
            if nums[i] not in mp:
                mp[nums[i]] = m
                m += 1
            nums[i] = mp[nums[i]]
        c = [0] * m
        for x in nums:
            c[x] += 1
        r = count(nums, c, True)
        nums.reverse()
        return add(r, count(nums, c, False))