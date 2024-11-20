#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static constexpr uint MAXN = 100'000;
    static int counts[3];
    static int window[3];
    
    static bool checkWindow(const int k) INL NO_SAN HOT {
        return window[0] <= counts[0] - k && 
               window[1] <= counts[1] - k && 
               window[2] <= counts[2] - k;
    }

public:
    static int takeCharacters(string& s, const int k) NO_SAN HOT {
        const int n = s.length();
        fill(counts, counts + 3, 0);
        
        for (const char c : s) {
            counts[c - 'a']++;
        }
        
        if (counts[0] < k || counts[1] < k || counts[2] < k) {
            return -1;
        }
        
        fill(window, window + 3, 0);
        int maxWindow = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            
            while (left <= right && !checkWindow(k)) {
                window[s[left] - 'a']--;
                left++;
            }
            
            maxWindow = max(maxWindow, right - left + 1);
        }
        
        return n - maxWindow;
    }
};

int Solution::counts[3];
int Solution::window[3];

static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();