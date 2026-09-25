class Solution:
    def largestPower(self, nums: List[int]) -> List[int]:
        blocks = [nums]
        power = [0] * 15
        
        for i in range(15):
            bit = 14 - i
            current_power = 0
            stopped = False
            new_blocks = []
            
            for block in blocks:
                if stopped:
                    new_blocks.append(block)
                else:
                    s_yes = []
                    s_no = []
                    for num in block:
                        if (num >> bit) & 1:
                            s_yes.append(num)
                        else:
                            s_no.append(num)
                            
                    if not s_no:
                        current_power += len(s_yes)
                        new_blocks.append(s_yes)
                    else:
                        current_power += len(s_yes)
                        if s_yes:
                            new_blocks.append(s_yes)
                        if s_no:
                            new_blocks.append(s_no)
                        stopped = True
                        
            power[i] = current_power
            blocks = new_blocks
            
        return power