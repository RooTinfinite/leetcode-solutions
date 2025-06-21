class Solution:
    def findLucky(self, arr: List[int]) -> int:
        final_dict={}
        for i in arr:
            if i in final_dict:
                final_dict[i]+=1
            else:
                final_dict[i]=1
        maxy=-1
        for key, value in final_dict.items():
            if key == value and key > maxy:
                maxy=key
        return maxy