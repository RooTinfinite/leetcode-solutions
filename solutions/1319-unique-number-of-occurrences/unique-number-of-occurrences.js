
var uniqueOccurrences = function(arr) {
    arr.sort((a, b) => a - b);
    let v = [];

    for (let i = 0; i < arr.length; i++) {
        let cnt = 1;

        // Count occurrences of the current element
        while (i + 1 < arr.length && arr[i] === arr[i + 1]) {
            cnt++;
            i++;
        }

        v.push(cnt);
    }

    v.sort((a, b) => a - b);

    for (let i = 1; i < v.length; i++) {
        if (v[i] === v[i - 1]) {
            return false;
        }
    }

    return true;
};

