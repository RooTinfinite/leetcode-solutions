class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        
        n_num = ''
        flip = False

        for i, v in enumerate(str(num)):
            val = int(v)
            if val < change[val]: 
                n_num += str(change[val])
                if not flip:
                    flip = True
            elif val == change[val]:
                n_num += v
            elif val > change[val]:
                if flip:
                    return n_num + num[i:]
                else:
                    n_num += v
        return n_num
                 