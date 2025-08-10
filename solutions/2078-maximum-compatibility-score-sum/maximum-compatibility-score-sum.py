class Solution:
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        # n questions, answers 0 or 1
        # m students 0..m-1
        # m mentors

        # student and mentors answered same questions of length n

        m = len(students)
        n = len(students[0])

        # compat between student i and mentor j: total indices where students[i] == mentors[j], i.e. num q's answered the same

        # maximize the sum of compat. scores

        # m,n  <= 8

        # DFS + BT?

        # wlog each student i gets matched with a mentor j

        # accelerate a bit by precomputing the compatibilities
        compats = [[0]*m for _ in range(m)]
        for i in range(m):
            for j in range(m):
                compats[i][j] = sum(a == b for a, b in zip(students[i], mentors[j]))

        # mentor_avail = [True]*m
        # max_compat = 0 # TODO: early pruning
        # def pair(i: int, compat: int):
        #     nonlocal max_compat
            
        #     if i == m:
        #         max_compat = max(max_compat, compat)
        #     else:
        #         for j in range(m):
        #             if not mentor_avail[j]: continue

        #             mentor_avail[j] = False
        #             pair(i+1, compat + compats[i][j])
        #             mentor_avail[j] = True

        # def pair(0, 0)

        # return max_avail

        # complexity: worst case we try all m pairings for student 0
        #  and for each, all m-1 pairings for student 1, etc.
        #  for 8!

        # better: we could record the max compatibility for students i: with a specific subset of mentors still available
        #     because we just need the total compatibility, not the details of the matching once we're done
        #
        # so for each i there would be m choose (m-i) == m choose i ways to have remaining items, only distinct subsets give different answers
        # and thus it's the sum of m choose i over all i, aka 2**m which is a lot better than m!

        ALL = (1 << m) - 1
        @cache
        def maxCompat(i: int, avail: int) -> int:
            if i == m: return 0

            ans = 0
            for j in range(m):
                b = 1 << j
                if avail & b:
                    # mentor is available: get max score where we bind i to j and continue with i+1 and remaining mentors
                    ans = max(ans, compats[i][j] + maxCompat(i+1, avail ^ b))

            return ans

        return maxCompat(0, ALL)