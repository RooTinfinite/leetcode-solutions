var numberOfSpecialChars = function (word) {
    const lastLow = new Array(26).fill(-1);
    const firstUp = new Array(26).fill(-1);
    for (let i = 0; i < word.length; i++) {
        const c = word[i];
        if (c >= "a" && c <= "z") {
            lastLow[c.charCodeAt(0) - 97] = i;
        } else {
            const idx = c.charCodeAt(0) - 65;
            if (firstUp[idx] === -1) firstUp[idx] = i;
        }
    }
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (lastLow[i] !== -1 && firstUp[i] !== -1 && lastLow[i] < firstUp[i]) {
            ans++;
        }
    }
    return ans;
};