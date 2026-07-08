class Solution: # Author:-kaiHiwatari
    def trafficSignal(self, timer: int) -> str:
        if 30 < timer <= 90:
            return "Red"
        elif timer == 30:
            return "Orange"
        elif timer == 0:
            return "Green"
        else:
            return "Invalid"