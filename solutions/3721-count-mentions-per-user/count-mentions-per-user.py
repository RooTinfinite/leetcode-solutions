class Solution:
    def countMentions(self, ndsvvfe: int, edkndnkne: List[List[str]]) -> List[int]:
        res = [0] * ndsvvfe 
        is_online = [1] * ndsvvfe
        edkndnkne.sort(key = lambda x: (int(x[1]), x[0] != "OFFLINE"))
        print(edkndnkne)
        
        for m, t, ids in edkndnkne:                  
            if m == "OFFLINE":
                is_online[int(ids)] = int(t) + 60
            else:
                if ids != "HERE" and ids != "ALL":
                    for id in ids.split(" "):
                        id = int(id[2:])
                        res[id] += 1
                elif ids == "ALL":
                    for i in range(len(is_online)):
                        res[i] += 1
                else:
                    for i in range(len(is_online)):
                        if is_online[i] <= int(t):
                            res[i] += 1

        return res