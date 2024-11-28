class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        hashmap = {}
        for cpdom in cpdomains:
            (num, domain) = (int(x) if i==0 else x for i, x in enumerate(cpdom.split(" ")))
            domains = domain.split('.')  # split the domain by '.'
            for idx in reversed(range(len(domains))):
                subdomain = '.'.join(domains[idx:])
                val = hashmap.get(subdomain, 0)  # 0 if not found in hashmap
                val += num
                hashmap[subdomain] = val
        
        # print(hashmap)
        ans = []
        for subdomain, count in hashmap.items():
            ans.append(" ".join([str(count), subdomain]))  # join count and subdomain using empty space (" ")
            
        return ans
        
        # Run / Memory: O(N)  N - number of elements in the cpdomains
        