function partition(s: string): string[][] {
    let len = s.length;
    let dp: boolean[][] = Array.from({ length: len }, () =>
        Array(len).fill(false),
    );
    let result: string[][] = [];
    dfs(result, s, 0, [], dp);
    return result;
}
function dfs(
    result: string[][],
    s: string,
    start: number,
    currentList: string[],
    dp: boolean[][],
) {
    if (start >= s.length) result.push([...currentList]);
    for (let end = start; end < s.length; end++) {
        if (
            s.charAt(start) === s.charAt(end) &&
            (end - start <= 2 || dp[start + 1][end - 1])
        ) {
            dp[start][end] = true;
            currentList.push(s.slice(start, end + 1));
            dfs(result, s, end + 1, currentList, dp);
            currentList.pop();
        }
    }
}