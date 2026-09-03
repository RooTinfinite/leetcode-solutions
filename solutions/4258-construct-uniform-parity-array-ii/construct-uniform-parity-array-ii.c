bool uniformArray(int* nums1, int nums1Size) {
    int mn = nums1[0];
    bool hasOdd = false;
    for (int i = 0; i < nums1Size; i++) {
        int v = nums1[i];
        if (v < mn) {
            mn = v;
        }
        if (v & 1) {
            hasOdd = true;
        }
    }
    if (mn & 1) {
        return true;
    }
    return !hasOdd;
}