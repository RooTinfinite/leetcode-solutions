var isValid = function (s) {
    const mappings = {
        ")": "(",
        "}": "{",
        "]": "[",
    };
    const stack = [];
    for (let c of s) {
        if (mappings[c]) {
            const topElement = stack.length ? stack.pop() : "#";
            if (topElement !== mappings[c]) {
                return false;
            }
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
};