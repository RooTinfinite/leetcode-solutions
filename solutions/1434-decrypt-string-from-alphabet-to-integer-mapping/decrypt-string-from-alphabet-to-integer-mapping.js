/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
  let result = ''

  let left = s.length - 1

  while (left >= 0) {
    if (s[left] === '#') {
      result = String.fromCharCode(96 + +(s[left - 2] + s[left - 1])) + result
      left -= 3
    } else {
      result = String.fromCharCode(96 + +s[left]) + result

      left--
    }
  }

  return result
};