var reversePrefix = function(s, k) {
    let arr = s.split("");
    let i = 0;
    k = k - 1;

    while (i < k) {
        [arr[i], arr[k]] = [arr[k], arr[i]];
        i++;
        k--;
    }

    return arr.join("");
};