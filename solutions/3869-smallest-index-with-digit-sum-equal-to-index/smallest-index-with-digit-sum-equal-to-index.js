var smallestIndex = function (nums) {
    const getDigitSum = (num) => {
        let sum = 0;

        while (num > 0) {
            sum += num % 10;
            num = Math.floor(num / 10);
        }

        return sum;
    };

    for (let i = 0; i < nums.length; i++) {
        if (getDigitSum(nums[i]) === i) {
            return i;
        }
    }

    return -1;
};