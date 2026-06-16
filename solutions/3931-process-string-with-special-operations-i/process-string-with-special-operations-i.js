function processStr(s) {
    let result = [];
    for (const ch of s) {
        if (ch === "*") {
            if (result.length) result.pop();
        } else if (ch === "#") {
            result = result.concat(result);
        } else if (ch === "%") {
            result.reverse();
        } else {
            result.push(ch);
        }
    }
    return result.join("");
}