class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        restaurants.sort(key=itemgetter(1,0),reverse=True)
        lst=[]
        """for i in restaurants:
            print(i)"""
        for i in restaurants:
            if veganFriendly==0:
                if i[3]<=maxPrice and i[4]<=maxDistance:
                    lst.append(i[0])    
            elif i[2]==veganFriendly and i[3]<=maxPrice and i[4]<=maxDistance:
                lst.append(i[0])
        return lst