class Solution:
  def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
    # adjacency list, net out degree
    G, D = defaultdict(list), defaultdict(int) 

    for u, v in pairs:
      G[u].append(v)
      D[u] += 1
      D[v] -= 1

    for node in D:
      if D[node] == 1:
        break

    res = []
    def dfs(node):
      while G[node]:
        nbr = G[node].pop()
        dfs(nbr)
        res.append((node, nbr))

    dfs(node)
    return res[::-1]
