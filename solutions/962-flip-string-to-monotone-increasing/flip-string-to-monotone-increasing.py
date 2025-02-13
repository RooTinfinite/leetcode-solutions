class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:

        ones, ans = 0, 0                    # Example: s = "010110"
                                            #
        for digit in s:                     #  num    ones   ans  
                                            #  ––––   ––––   ––––  
            if digit =='1': ones += 1       #    0      0     0
                                            #    1      1     0
            elif ones:                      #    0      0     1
                ones -= 1                   #    1      1     1
                ans += 1                    #    1      2     1
                                            #    0      1     2
        return ans