class Solution
{
    public boolean maxSubstringLength(String s, int k)
    {
        int strLen = s.length();
        if (k == 0)
        {
            return true;
        } 
            

        int[] firstOccur = new int[26];
        int[] lastOccur = new int[26];

        Arrays.fill(firstOccur, strLen);
        Arrays.fill(lastOccur, -1);

        // Step 1: Find first and last occurrence of each character
        for (int pos = 0; pos < strLen; pos++)
        {
            int charIdx = s.charAt(pos) - 'a';
            firstOccur[charIdx] = Math.min(firstOccur[charIdx], pos);
            lastOccur[charIdx] = Math.max(lastOccur[charIdx], pos);
        }

        List<int[]> segments = new ArrayList<>();

        // Step 2: Find valid segments
        for (int start = 0; start < strLen; start++)
        {
            if (start != firstOccur[s.charAt(start) - 'a'])
            {
                continue;
            } 

            int farthest = lastOccur[s.charAt(start) - 'a'];
            int current = start;
            boolean isValid = true;

            while (current <= farthest)
            {
                if (firstOccur[s.charAt(current) - 'a'] < start)
                {
                    isValid = false;
                    break;
                }
                
                farthest = Math.max(farthest, lastOccur[s.charAt(current) - 'a']);
                current++;
            }

            if (isValid && !(start == 0 && farthest == strLen - 1))
            {
                segments.add(new int[]{start, farthest});
            }
        }

        // Step 3: Sort the segments based on ending index
        segments.sort(Comparator.comparingInt(pair -> pair[1]));

        // Step 4: Count non-overlapping segments
        int segmentCount = 0, lastIndex = -1;
        for (int[] bounds : segments)
        {
            if (bounds[0] > lastIndex)
            {
                segmentCount++;
                lastIndex = bounds[1];
            }
        }

        return segmentCount >= k;
    }
}