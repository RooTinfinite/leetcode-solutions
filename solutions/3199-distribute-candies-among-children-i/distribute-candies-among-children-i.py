class Solution:
    def distributeCandies(self, n, limit):
        ret_val = 0

        count_candies_1 = 0
        while (count_candies_1 <= limit):
            count_candies_2 = 0
            while (count_candies_2 <= limit):
                count_candies_3 = n - count_candies_1 - count_candies_2
                if (0 <= count_candies_3 <= limit):
                    ret_val += 1
                count_candies_2 += 1
            count_candies_1 += 1

        return ret_val