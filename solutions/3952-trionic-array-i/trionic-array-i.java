interface ISequenceCheck {
    boolean validate(int[] arr, int start, int end);
}

class IncreasingCheck implements ISequenceCheck {
    @Override
    public boolean validate(int[] arr, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] <= arr[i - 1]) return false;
        }
        return true;
    }
}

class DecreasingCheck implements ISequenceCheck {
    @Override
    public boolean validate(int[] arr, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] >= arr[i - 1]) return false;
        }
        return true;
    }
}

class TrionicArrayChecker {
    private final ISequenceCheck prefixCheck;
    private final ISequenceCheck valleyCheck;
    private final ISequenceCheck suffixCheck;

    public TrionicArrayChecker(ISequenceCheck pre, ISequenceCheck valley, ISequenceCheck suf) {
        this.prefixCheck = pre;
        this.valleyCheck = valley;
        this.suffixCheck = suf;
    }

    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        if (n < 3) return false;

        boolean[] suffixIncreasing = new boolean[n];
        suffixIncreasing[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i] && suffixIncreasing[i + 1]) {
                suffixIncreasing[i] = true;
            } else {
                suffixIncreasing[i] = false;
            }
        }

        for (int p = 1; p <= n - 3; ++p) {
            if (!prefixCheck.validate(nums, 0, p)) break;

            int j = p + 1;
            while (j <= n - 2 && nums[j] < nums[j - 1]) {
                if (suffixIncreasing[j]) return true;
                ++j;
            }
        }
        return false;
    }
}

public class Solution {
    public boolean isTrionic(int[] nums) {
        TrionicArrayChecker checker = new TrionicArrayChecker(
            new IncreasingCheck(),
            new DecreasingCheck(),
            new IncreasingCheck()
        );
        return checker.isTrionic(nums);
    }
}