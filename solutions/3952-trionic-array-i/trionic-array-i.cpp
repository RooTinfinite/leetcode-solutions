#include <vector>
#include <memory>
using namespace std;

class ISequenceCheck {
public:
    virtual ~ISequenceCheck() = default;
    virtual bool validate(const vector<int>& arr, int start, int end) const = 0;
};

class IncreasingCheck : public ISequenceCheck {
public:
    bool validate(const vector<int>& arr, int start, int end) const override {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] <= arr[i - 1]) return false;
        }
        return true;
    }
};

class DecreasingCheck : public ISequenceCheck {
public:
    bool validate(const vector<int>& arr, int start, int end) const override {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] >= arr[i - 1]) return false;
        }
        return true;
    }
};

class TrionicArrayChecker {
    const unique_ptr<ISequenceCheck> prefixCheck;
    const unique_ptr<ISequenceCheck> valleyCheck;
    const unique_ptr<ISequenceCheck> suffixCheck;
public:
    TrionicArrayChecker(unique_ptr<ISequenceCheck> pre,
                        unique_ptr<ISequenceCheck> valley,
                        unique_ptr<ISequenceCheck> suf)
        : prefixCheck(move(pre)), valleyCheck(move(valley)), suffixCheck(move(suf)) {}

    bool isTrionic(const vector<int>& nums) const {
        int n = nums.size();
        if (n < 3) return false;
        vector<bool> suffixIncreasing(n, false);
        suffixIncreasing[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i+1] > nums[i] && suffixIncreasing[i+1]) suffixIncreasing[i] = true;
            else suffixIncreasing[i] = false;
        }
        for (int p = 1; p <= n - 3; ++p) {
            if (!prefixCheck->validate(nums, 0, p)) break;
            int j = p + 1;
            while (j <= n - 2 && nums[j] < nums[j - 1]) {
                if (suffixIncreasing[j]) return true;
                ++j;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        TrionicArrayChecker checker(
            make_unique<IncreasingCheck>(),
            make_unique<DecreasingCheck>(),
            make_unique<IncreasingCheck>()
        );
        return checker.isTrionic(nums);
    }
};