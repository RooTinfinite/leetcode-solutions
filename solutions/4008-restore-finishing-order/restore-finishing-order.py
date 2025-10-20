class Solution(object):
    def recoverOrder(self, order, friends):
        l = []
        for i in order:
            if i in friends:
                l.append(i)
        return l