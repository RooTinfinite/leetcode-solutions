/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const stack = [];
    const result = new Array(temperatures.length).fill(0);

    for (let i = temperatures.length - 1; i >= 0; --i) {
        while (stack.length > 0 && temperatures[i] >= temperatures[stack[0]]) {
            stack.shift();
        }

        if (stack.length === 0) {
            result[i] = 0;
        } else {
            result[i] = stack[0] - i;
        }

        stack.unshift(i);
    }

    return result;
};

