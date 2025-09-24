class Solution {
    std::string getMergedString(const std::string& a, const std::string& b)
    {
        int n = a.size(), m = b.size();
        for (int i{}; i < n; ++i) {
            int k{i}, j{};
            for (; j < m && k < n; ++j) {
                if (a[k] == b[j]) ++k;
                else break;
            }

            if (j == m) return a;
            if (k == n) return a + b.substr(j);
        }

        return a + b;
    }

    std::string evaluateSequence(const std::string& a, const std::string& b, const std::string& c)
    {
        std::string res{getMergedString(getMergedString(a, b), c)};
        return res;
    }
public:
    string minimumString(string a, string b, string c) {
        std::string res;
        std::size_t minLen{std::numeric_limits<int>::max()};
        std::vector<std::string> vec;
        vec.push_back(evaluateSequence(a, b, c));
        vec.push_back(evaluateSequence(a, c, b));
        vec.push_back(evaluateSequence(b, a, c));
        vec.push_back(evaluateSequence(b, c, a));
        vec.push_back(evaluateSequence(c, a, b));
        vec.push_back(evaluateSequence(c, b, a));

        for (const std::string& s : vec) {
            if (s.size() < minLen) {
                minLen = s.size();
                res = s;
            } else if (minLen == s.size() && res > s) {
                res = s;
            }
        }
  
        return res; 
    }
};