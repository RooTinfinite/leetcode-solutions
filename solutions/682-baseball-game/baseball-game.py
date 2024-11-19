class Solution:
    def calPoints(self, s: List[str]) -> int:
    	s, i = [int(s[i]) if s[i] not in 'CD+' else s[i] for i in range(len(s))]+[''], 1
    	while s[i] != '':
    		if s[i] == 'C':
    			del s[i-1], s[i-1]
    			i -= 1
    			continue
    		i += 1
    	for i in range(len(s)-1):
    		if s[i] == 'D': s[i] = 2*s[i-1]
    		if s[i] == '+': s[i] = s[i-2] + s[i-1]
    	return sum(s[:len(s)-1])
		

