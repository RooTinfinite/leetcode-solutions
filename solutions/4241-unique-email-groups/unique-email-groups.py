class Solution:
    def uniqueEmailGroups(self, emails: list[str]) -> int:

        res = set()
        
        for email in emails:

            local, domain = email.lower().split("@")
            local = local.split('+')[0].replace('.', '')
            
            res.add( "@".join([local, domain]))

        return len(res)