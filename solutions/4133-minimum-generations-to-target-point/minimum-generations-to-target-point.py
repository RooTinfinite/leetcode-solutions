class Solution:
    def cal(self, a, b):
        xa, ya, za = a // 100, (a % 100) // 10, a % 10
        xb, yb, zb = b // 100, (b % 100) // 10, b % 10

        return (100 * ((xa + xb) // 2) + 10 * ((ya + yb) // 2) + (za + zb) // 2)

    def minGenerations(self, points, target):
        s = set()

        for x, y, z in points:
            s.add(100 * x + 10 * y + z)

        t = 100 * target[0] + 10 * target[1] + target[2]

        ans = 0

        while t not in s:
            temp = set(s)

            arr = list(s)

            for i in range(len(arr)):
                for j in range(i + 1, len(arr)):
                    temp.add(self.cal(arr[i], arr[j]))

            if temp == s:
                return -1

            s = temp
            ans += 1

        return ans