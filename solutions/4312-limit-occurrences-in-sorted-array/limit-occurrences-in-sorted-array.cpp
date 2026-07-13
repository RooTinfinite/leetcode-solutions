class Solution {
public:
    vector<int> limitOccurrences(vector<int>& A, int k) {
        int i = 0;

        for (auto& n : A)
            if (i < k || n != A[i - k])
                A[i++] = n;

        while (A.size() > i) A.pop_back();

        return A;
    }
};