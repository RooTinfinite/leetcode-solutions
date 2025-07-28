class Solution(object):
    def findingUsersActiveMinutes(self, logs, k):
        """
        :type logs: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        user_minutes = defaultdict(set)

        for user_id, time in logs:
            user_minutes[user_id].add(time)

        result = [0] * k
        for minutes in user_minutes.values():
            uam = len(minutes)
            if uam <= k:
                result[uam - 1] += 1

        return result