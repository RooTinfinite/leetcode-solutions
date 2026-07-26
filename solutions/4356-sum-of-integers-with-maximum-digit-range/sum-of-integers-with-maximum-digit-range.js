const maxDigitRange = (nums) => {
    const ranges = nums.map(getRange);
    const maxRange = Math.max(...ranges);
    return nums
        .filter((_, i) => ranges[i] === maxRange)
        .reduce((s, v) => s + v, 0);
};

const getRange = (num) =>
{
    const digits = [...`${num}`].sort();
    return digits.at(-1) - digits.at(0);
}