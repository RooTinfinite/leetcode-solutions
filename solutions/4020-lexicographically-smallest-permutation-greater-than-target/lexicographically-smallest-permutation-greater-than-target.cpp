class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        map<char, int> s_counts;
        for (char c : s) {
            s_counts[c]++;
        }

        string best_solution = ""; // Use to store the best result found so far

        map<char, int> prefix_counts;
        for (int i = 0; i < n; ++i) {
            // Create a copy of counts available for suffix and pivot
            map<char, int> available_counts = s_counts;
            for (auto const& [key, val] : prefix_counts) {
                available_counts[key] -= val;
            }

            // Find the smallest char > target[i] to use as the pivot
            for (char pivot_char = target[i] + 1; pivot_char <= 'z';
                 ++pivot_char) {
                if (available_counts.count(pivot_char) &&
                    available_counts[pivot_char] > 0) {
                    // We found a valid pivot character
                    available_counts[pivot_char]--;

                    string current_prefix = target.substr(0, i);
                    string suffix = "";
                    for (char k = 'a'; k <= 'z'; ++k) {
                        if (available_counts.count(k)) {
                            suffix += string(available_counts[k], k);
                        }
                    }

                    string candidate = current_prefix + pivot_char + suffix;
                    if (best_solution == "" || candidate < best_solution) {
                        best_solution = candidate;
                    }

                    // Since we want the smallest pivot_char, we can break after
                    // finding one
                    break;
                }
            }

            // Update prefix_counts for the next iteration
            prefix_counts[target[i]]++;
            if (prefix_counts[target[i]] > s_counts[target[i]]) {
                // We can't match the target's prefix any further, so we can
                // stop.
                break;
            }
        }

        return best_solution;
    }
};