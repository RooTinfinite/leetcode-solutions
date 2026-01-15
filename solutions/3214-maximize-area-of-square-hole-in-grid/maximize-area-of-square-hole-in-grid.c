int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars,
                           int vBarsSize) {
    qsort(hBars, hBarsSize, sizeof(int), compare);
    qsort(vBars, vBarsSize, sizeof(int), compare);
    int hmax = 1, vmax = 1;
    int hcur = 1, vcur = 1;
    for (int i = 1; i < hBarsSize; i++) {
        if (hBars[i] == hBars[i - 1] + 1) {
            hcur++;
        } else {
            hcur = 1;
        }
        hmax = fmax(hmax, hcur);
    }
    for (int i = 1; i < vBarsSize; i++) {
        if (vBars[i] == vBars[i - 1] + 1) {
            vcur++;
        } else {
            vcur = 1;
        }
        vmax = fmax(vmax, vcur);
    }
    int side = fmin(hmax, vmax) + 1;
    return side * side;
}