class Solution(object):
    def asteroidsDestroyed(self, mass, asteroids):
        asteroids.sort()
        temp = mass
        for a in asteroids:
            if a <= temp:
                temp += a
            else:
                return False
        return True