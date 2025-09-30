/**
 * @param {number[]} colors
 * @return {number}
 */
var numberOfAlternatingGroups = function (colors) {
    var res = 0;
    var n = colors.length;
    for (var i = 0; i < colors.length; ++i) {
        var pre = colors[i];
        var cur = colors[(i + 1) % n];
        var nxt = colors[(i + 2) % n];
        if (pre !== cur && cur !== nxt) ++res;
    }
    return res;
};