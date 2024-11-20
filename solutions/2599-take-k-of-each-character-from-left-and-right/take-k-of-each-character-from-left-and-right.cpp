#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define ALIGNED __attribute__((aligned(64)))
#define RESTRICT __restrict__
#define PURE __attribute__((pure))
#define CONST __attribute__((const))

class Solution {
private:
    static constexpr uint MAXV = 100'000;
    alignas(64) static uint16_t freqs[3];

    static bool checkFreqs(const int k) INL NO_SAN HOT PURE {
        return __builtin_expect((freqs[0] >= k && freqs[1] >= k && freqs[2] >= k), 1);
    }

    static void updateWindow(uint16_t* RESTRICT window, char c, int delta) INL NO_SAN HOT {
        window[c - 'a'] += delta;
    }

    static bool isValidWindow(const uint16_t* RESTRICT window, const int k) INL NO_SAN HOT PURE {
        return (freqs[0] - window[0] >= k) & 
               (freqs[1] - window[1] >= k) & 
               (freqs[2] - window[2] >= k);
    }

public:
    static int takeCharacters(string& RESTRICT s, const int k) NO_SAN HOT {
        const int n = s.length();
        
        #pragma GCC unroll 3
        for (int i = 0; i < 3; ++i) {
            freqs[i] = 0;
        }
        
        #pragma GCC ivdep
        for (char c : s) {
            ++freqs[c - 'a'];
        }
        
        if (!checkFreqs(k)) {
            return -1;
        }

        int result = n;
        int left = 0;
        alignas(64) uint16_t window[3] = {0};

        #pragma GCC optimize("unroll-loops")
        for (int right = 0; right < n; right++) {
            updateWindow(window, s[right], 1);
            
            while (left <= right && !isValidWindow(window, k)) {
                updateWindow(window, s[left++], -1);
            }
            
            result = min(result, n - (right - left + 1));
        }
        
        return result;
    }
};

alignas(64) uint16_t Solution::freqs[3];

[[maybe_unused]] static auto init = []() NO_SAN HOT {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
    return 'c';
}();
