var generateParenthesis = function (n) {
    if (n === 0) {
        return [""];
    }
    let answer = [];
    for (let leftCount = 0; leftCount < n; ++leftCount) {
        let leftStrings = generateParenthesis(leftCount);
        let rightStrings = generateParenthesis(n - 1 - leftCount);
        for (let leftString of leftStrings) {
            for (let rightString of rightStrings) {
                answer.push("(" + leftString + ")" + rightString);
            }
        }
    }
    return answer;
};