class Solution:
    def subtreeInversionSum(self, edges: list[list[int]], nums: list[int], k: int) -> int:
        n = len(nums)
        conn = [[] for _ in range(n)]
        for u, v in edges:
            conn[u].append(v)
            conn[v].append(u)

        def dfs(node: int, parent: int) -> (List[int], List[int]):
            mxs, mns = [nums[node]]*k, [nums[node]]*k
            for child in conn[node]:
                if child == parent:
                    continue
                cmx, cmn = dfs(child, node)

                # left inv depth >= i+1 and right inv depth >= k-i-1 or
                # left inv depth >= k-i-1 and right inv depth >= i+1
                for i in range(k//2):
                    mxs[i] = max(mxs[i]+cmx[k-i-2], mxs[k-i-2]+cmx[i])
                    mns[i] = min(mns[i]+cmn[k-i-2], mns[k-i-2]+cmn[i])
                
                # left inv depth >= i+1 and right inv depth >= i+1
                for i in range(k//2,k):
                    mxs[i] += cmx[i]
                    mns[i] += cmn[i]

                # suffix max/min
                for i in reversed(range(k-1)):
                    mxs[i] = max(mxs[i], mxs[i+1])
                    mns[i] = min(mns[i], mns[i+1])

            # invert or not invert
            mxs.insert(0, max(mxs[0], -mns[-1]))
            mns.insert(0, min(mns[0], -mxs[-1]))
            mxs.pop()
            mns.pop()
            return mxs, mns
            
        mxs, mns = dfs(0, -1)
        return mxs[0]