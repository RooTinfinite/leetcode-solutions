#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static constexpr uint MAXV = 100'000;
    static uint16_t freqs[3];

    static bool checkFreqs(const int k) INL NO_SAN HOT {
        return freqs[0] >= k && freqs[1] >= k && freqs[2] >= k;
    }

public:
    static int takeCharacters(string& s, const int k) NO_SAN HOT {
        const int n = s.length();
        fill(freqs, freqs + 3, 0);
        
        for (char c : s) {
            freqs[c - 'a']++;
        }
        
        if (!checkFreqs(k)) {
            return -1;
        }

        int result = n;
        int left = 0;
        uint16_t window[3] = {0, 0, 0};

        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            
            while (freqs[0] - window[0] < k || 
                   freqs[1] - window[1] < k || 
                   freqs[2] - window[2] < k) {
                window[s[left] - 'a']--;
                left++;
            }
            
            result = min(result, n - (right - left + 1));
        }
        
        return result;
    }
};

uint16_t Solution::freqs[3];

static auto init = []() NO_SAN HOT {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
