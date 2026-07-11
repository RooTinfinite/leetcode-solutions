const minFlips = (s, f = [0, 0]) => {
    for (const c of s) f[c & 1]++;

    if (!f[0] || !f[1]) return 0;
    
    return Math.min(
        f[0], f[1] - (s[0] & s.at(-1)) - 1
    );
};