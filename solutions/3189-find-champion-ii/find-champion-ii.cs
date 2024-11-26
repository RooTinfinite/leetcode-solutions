public class Solution {
    public int FindChampion(int n, int[][] edges) {
        bool[] isUndefeated = new bool[n];
        Array.Fill(isUndefeated, true);
        
        foreach (var edge in edges) {
            int winner = edge[0], loser = edge[1];
            isUndefeated[loser] = false;
        }
        
        int champion = -1;
        int championCount = 0;
        
        for (int team = 0; team < n; team++) {
            if (isUndefeated[team]) {
                champion = team;
                championCount++;
            }
        }
        
        return championCount == 1 ? champion : -1;
    }
}