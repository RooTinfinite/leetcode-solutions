#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static uint mod1(const uint i, const uint n) INL NO_SAN HOT {
        return i - (-(i >= n) & n);
    }

public:
    static vector<int> decrypt(vector<int> &code, const int8_t k) INL NO_SAN HOT {
        const uint8_t n = code.size();
        if (k < 0) {
            uint s = reduce(code.cbegin() + (n + k), code.cend());
            transform(code.cbegin(), code.cend(), code.begin(), [](const uint8_t v) INL NO_SAN HOT { return v << 16; });
            for (uint8_t i = 0; i < n; i++) {
                const uint8_t v = code[i] >> 16;
                code[i] += s;
                const uint8_t j = mod1(n + k + i, n);
                s += v - (code[j] >> 16);
            }
            transform(code.cbegin(), code.cend(), code.begin(), [](const uint v) INL NO_SAN HOT { return v & 0x3FFF; });
        } else if (k > 0) {
            uint s = reduce(code.cbegin(), code.cbegin() + k);
            transform(code.cbegin(), code.cend(), code.begin(), [](const uint8_t v) INL NO_SAN HOT { return v << 16; });
            for (uint8_t i = 0; i < n; i++) {
                const uint8_t v = code[i] >> 16;
                const uint8_t j = mod1(i + k, n);
                s += (code[j] >> 16) - v;
                code[i] += s;
            }
            transform(code.cbegin(), code.cend(), code.begin(), [](const uint v) INL NO_SAN HOT { return v & 0x3FFF; });
        } else {
            fill(code.begin(), code.end(), 0);
        }
        return move(code);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
