/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function (arr1, arr2) {
    let commonPrefixSet = new Set();
    let res = 0;
    for (let i = 0; i < arr1.length; i++) {
        let str = String(arr1[i])
        for (j = 1; j <= str.length; j++) {
            commonPrefixSet.add(str.substring(0, j))
        }
    }
    for (let i = 0; i < arr2.length; i++) {
        let str = String(arr2[i])
        for (let j = 1; j <= str.length; j++) {
            if (commonPrefixSet.has(str.substring(0, j))) {
                res = Math.max(res, str.substring(0, j).length)
            }
        }
    }

    return res;

};
