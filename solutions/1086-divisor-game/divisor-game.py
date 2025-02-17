class Solution(object):
    def divisorGame(self, n):
        winner = 0
        while n!=1:
            winner += 1
            n -= 1
        
        if winner%2==0:   
            return False 
        else:
            return True

                


            
        