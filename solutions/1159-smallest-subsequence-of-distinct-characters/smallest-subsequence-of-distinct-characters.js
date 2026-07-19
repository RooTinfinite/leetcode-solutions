var smallestSubsequence = function (s) {
    const vis = new Array(26).fill(0);
    const num = _.countBy(s);

    const sb = new Array();
    for (let i = 0; i < s.length; i++) {
        const ch = s[i];
        if (!vis[ch.charCodeAt() - "a".charCodeAt()]) {
            while (sb.length > 0 && sb[sb.length - 1] > ch) {
                if (num[sb[sb.length - 1]] > 0) {
                    vis[sb[sb.length - 1].charCodeAt() - "a".charCodeAt()] = 0;
                    sb.pop();
                } else {
                    break;
                }
            }
            vis[ch.charCodeAt() - "a".charCodeAt()] = 1;
            sb.push(ch);
        }
        num[ch]--;
    }
    return sb.join("");
};