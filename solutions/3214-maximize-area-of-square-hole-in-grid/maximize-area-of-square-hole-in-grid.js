function maximizeSquareHoleArea(n, m, hBars, vBars) {
    hBars.sort((a, b) => a - b);
    vBars.sort((a, b) => a - b);
    let hmax = 1,
        vmax = 1;
    let hcur = 1,
        vcur = 1;
    for (let i = 1; i < hBars.length; i++) {
        if (hBars[i] === hBars[i - 1] + 1) {
            hcur++;
        } else {
            hcur = 1;
        }
        hmax = Math.max(hmax, hcur);
    }
    for (let i = 1; i < vBars.length; i++) {
        if (vBars[i] === vBars[i - 1] + 1) {
            vcur++;
        } else {
            vcur = 1;
        }
        vmax = Math.max(vmax, vcur);
    }
    const side = Math.min(hmax, vmax) + 1;
    return side * side;
}