class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        ages.sort(reverse = True)
        nb_request = 0
        i = 0
        dict_ages = {}
        while i < len(ages) -1:
            x = ages[i]
            if x in dict_ages.keys():
                nb_request += dict_ages[x]
                #print('adding:', dict_ages)
            else:
                current_nb_request = 0
                condition = 0.5*x + 7
                tmp_i = i +1
                y = ages[tmp_i]
                while y > condition and tmp_i < len(ages):
                    y = ages[tmp_i]
                    if y > condition:
                        current_nb_request += 1
                    tmp_i += 1
                nb_request += current_nb_request
                dict_ages[x] = current_nb_request
                #print('new dict', dict_ages[x])
            i += 1
        nb_request += dict_ages.get(ages[-1],0)
        return nb_request
                
                
                
            
                
                
                 
            
        