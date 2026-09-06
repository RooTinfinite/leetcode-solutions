class Solution:
    def countGroups(self, position: list[int], speed: list[int], distance: int) -> int:
        n = len(position)

        # INITIAL MERGES
        # new_pos = [] 
        new_spd = []
        i = 0
        while i < n:
            j = i
            while j+1 < n and position[j] >= position[j+1] - distance:
                j += 1
            # new_pos.append(position[j])
            new_spd.append(speed[j])
            i = j + 1

        # SUBSEQUENT MERGES
        # position = new_pos
        speed = new_spd
        n = len(speed)
        ans = 0
        i = n - 1
        while i >= 0:
            j = i
            while j - 1 >= 0 and speed[i] < speed[j-1]:
                j -= 1
            ans += 1
            i = j - 1

        return ans