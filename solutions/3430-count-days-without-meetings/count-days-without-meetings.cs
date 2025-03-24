public class Solution {
    public int CountDays(int days, int[][] meetings) {
        Array.Sort(meetings, (x, y) => x[0].CompareTo(y[0]));
        int start = meetings[0][0];
        int end = meetings[0][1];
        List<int[]> res = new List<int[]>();
        int freeDays = 0;
        for(int i = 1; i < meetings.Length; i++)
        {
            if(meetings[i][0] <= end)
            {
                end = Math.Max(end, meetings[i][1]);
            }
            else {
                res.Add(new int[2] {start, end});                
                freeDays += (meetings[i][0] - res[res.Count-1][1]) - 1;
                start = meetings[i][0];
                end = meetings[i][1];
                
            }                                                                                                                       
        }
        res.Add(new int[2] {start, end});
        int advanceStartDays = res[0][0] - 1;
        int remainingEndDays = days - res[res.Count-1][1];
        return freeDays + advanceStartDays + remainingEndDays;
    }
}

/*
4, 8
[1,3][2,7][9,10]
[1,7][9,10]
[1,3][2,4]
*/