#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static constexpr uint8_t SH = 18;
    static constexpr uint64_t CMASK = 0x1000040001ull, SMASK = CMASK << (SH - 1);

    static bool vlto(const uint64_t vsa, const uint64_t vb) INL NO_SAN HOT {
        return ((vsa - vb) & SMASK) != SMASK;
    }

public:
    static int takeCharacters(const string &s, const uint k) NO_SAN HOT {
        const uint64_t vk = k * CMASK;
        const uint n = s.length();
        if (!k) return 0;
        uint l = 0, r = n - 1u;
        uint64_t vcnt = SMASK;
        bool lt = true;
        [[unroll(8)]]
        for ( ; l < n && lt; l++) {
            const uint8_t i = s[l] - 'a';
            vcnt += 1ull << (i * SH);
            lt = vlto(vcnt, vk);
        }
        if (lt) return -1;
        uint res = l;
        [[unroll(4)]]
        while (l--) {
            {
                const uint8_t i = s[l] - 'a';
                vcnt -= 1ull << (i * SH);
            }
            for (r++; r-- && vlto(vcnt, vk); ) {
                const uint8_t j = s[r] - 'a';
                vcnt += 1ull << (j * SH);
            }
            res = min(res, l + n - r - 1u);
        }
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();