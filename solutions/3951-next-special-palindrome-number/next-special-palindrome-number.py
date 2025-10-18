from itertools import permutations

def findSubsets(arr, index, target, curr, result, max_odds, odd_count):
    if index >= len(arr):
        if target == 0:
            result.append(curr[:])
        return

    if odd_count + (arr[index] % 2) <= max_odds:
        curr.append(arr[index])
        findSubsets(arr, index + 1, target - arr[index], curr, result, max_odds, odd_count + (arr[index] % 2))
        curr.pop()

    findSubsets(arr, index + 1, target, curr, result, max_odds, odd_count)

def perfectSum(arr, target, max_odds):
    result = []
    findSubsets(arr, 0, target, [], result, max_odds, 0)
    return result

arr1 = [2, 4, 6, 8]
arr2 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
L = set()
for i in range(2, 17):
    if i % 2 == 0:
        res = perfectSum(arr1, i, max_odds=len(arr1))
    else:
        res = perfectSum(arr2, i, max_odds=1)
    x = False
    for arr in res:
        s = ""
        for i in arr:
            if i % 2 == 1:
                x = True
                t = i
            s += str(i) * (i//2)
        perms = permutations(s)
        for p in perms:
            s = "".join(p)
            if x:
                L.add(s + str(t) + s[::-1])
            else:
                L.add(s + s[::-1])
L1 = [int(i) for i in L]
L1.sort()
class Solution:
    def specialPalindrome(self, n: int) -> int:
        if n == 0:
            return 1
        x = bisect.bisect_right(L1, n)
        return L1[x]