var largestEven = function(s) {
    let ind = -1;

    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === '2') {
            ind = i;
            break;
        }
    }

    return s.slice(0, ind + 1);
};