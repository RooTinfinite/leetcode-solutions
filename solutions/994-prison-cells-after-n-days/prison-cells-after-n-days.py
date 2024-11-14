class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:

        seen = dict()
        is_fast_forwarded = False

        while N > 0:
            # we only need to run the fast-forward once at most
            if not is_fast_forwarded:
                state_key = tuple(cells)
                if state_key in seen:
                    # the length of the cycle is seen[state_key] - N 
                    N %= seen[state_key] - N
                    is_fast_forwarded = True
                else:
                    seen[state_key] = N

            # check if there is still some steps remained,
            # with or without the fast-forwarding.
            if N > 0:
                N -= 1
                next_day_cells = self.nextDay(cells)
                cells = next_day_cells

        return cells


    def nextDay(self, cells: List[int]):
        ret = [0]      # head
        for i in range(1, len(cells)-1):
            ret.append(int(cells[i-1] == cells[i+1]))
        ret.append(0)  # tail
        return ret