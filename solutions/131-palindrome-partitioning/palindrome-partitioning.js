var partition = function (s) {
    let len = s.length;
    let dp = Array(len)
        .fill()
        .map(() => Array(len).fill(false));
    let result = [];
    dfs(result, s, 0, [], dp);
    return result;
};
function dfs(result, s, start, currentList, dp) {
    if (start >= s.length) result.push([...currentList]);
    for (let end = start; end < s.length; end++) {
        if (
            s[start] === s[end] &&
            (end - start <= 2 || dp[start + 1][end - 1])
        ) {
            dp[start][end] = true;
            currentList.push(s.slice(start, end + 1));
            dfs(result, s, end + 1, currentList, dp);
            currentList.pop();
        }
    }
}