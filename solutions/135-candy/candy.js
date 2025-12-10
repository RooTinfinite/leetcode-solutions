var candy = function (ratings) {
    var sum = 0;
    var len = ratings.length;
    var left2right = new Array(len).fill(1);
    var right2left = new Array(len).fill(1);
    for (var i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }
    for (var i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }
    for (var i = 0; i < len; i++) {
        sum += Math.max(left2right[i], right2left[i]);
    }
    return sum;
};