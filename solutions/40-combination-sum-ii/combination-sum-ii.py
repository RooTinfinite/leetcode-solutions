class Solution:
    def combinationSum2(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:
        def backtrack(answer, temp_list, candidates, total_left, index):
            if total_left < 0:
                return
            elif total_left == 0:
                answer.append(temp_list.copy())
            else:
                for i in range(index, len(candidates)):
                    if i > index and candidates[i] == candidates[i - 1]:
                        continue
                    if total_left < candidates[i]:
                        break
                    temp_list.append(candidates[i])
                    backtrack(
                        answer,
                        temp_list,
                        candidates,
                        total_left - candidates[i],
                        i + 1,
                    )
                    temp_list.pop()

        result = []
        candidates.sort()
        backtrack(result, [], candidates, target, 0)
        return result