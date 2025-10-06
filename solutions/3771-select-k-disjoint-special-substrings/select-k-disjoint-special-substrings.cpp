class Solution
{
public:
    bool maxSubstringLength(std::string s, int k)
    {
        int strLen = s.size();
        if (k == 0)
        {
            return true;
        } 
        
        std::vector<int> firstOccur(26, strLen), lastOccur(26, -1);
        
        // Step 1: Find first and last occurrence of each character
        for (int pos = 0; pos < strLen; pos++)
        {
            int charIdx = s[pos] - 'a';
            firstOccur[charIdx] = std::min(firstOccur[charIdx], pos);
            lastOccur[charIdx] = std::max(lastOccur[charIdx], pos);
        }

        std::vector<std::pair<int, int>> segments;
        
        // Step 2: Find valid segments
        for (int start = 0; start < strLen; start++)
        {
            if (start != firstOccur[s[start] - 'a'])
            {
                continue;
            } 

            int farthest = lastOccur[s[start] - 'a'];
            int current = start;
            bool isValid = true;

            while (current <= farthest)
            {
                if (firstOccur[s[current] - 'a'] < start)
                {
                    isValid = false;
                    break;
                }
                
                farthest = std::max(farthest, lastOccur[s[current] - 'a']);
                current++;
            }

            if (isValid && !(start == 0 && farthest == strLen - 1))
            {
                segments.emplace_back(start, farthest);
            }
        }

        // Step 3: Sort the segments based on ending index
        std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return a.second < b.second;
        });

        // Step 4: Count non-overlapping segments
        int segmentCount = 0, lastIndex = -1;
        for (const auto& bounds : segments)
        {
            if (bounds.first > lastIndex)
            {
                segmentCount++;
                lastIndex = bounds.second;
            }
        }

        return segmentCount >= k;
    }
};