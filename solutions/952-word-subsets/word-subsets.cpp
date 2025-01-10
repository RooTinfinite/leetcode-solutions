class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        auto get_word_freqs {[](string& w) -> array<int, 26> {
            array<int, 26> ret {};
            for (auto c : w)
                ++ret[c - 'a'];

            return ret;
        }};

        array<int, 26> words2_max_freqs {};
        for (auto& w : words2) {
            const auto current {get_word_freqs(w)};
            for (int i {0}; i < 26; ++i)
                words2_max_freqs[i] = max (words2_max_freqs[i], current[i]);
        }

        vector<string> ret {};
        ret.reserve (words1.size());

        for (auto& w : words1) {
            const auto current {get_word_freqs(w)};

            bool is_universal {true};
            for (int i {0}; i < 26; ++i)
                if (current[i] < words2_max_freqs[i]) {
                    is_universal = false;
                    break;
                }     

            if (is_universal)
                ret.push_back (std::move(w));
        }

        return ret;
    }
};