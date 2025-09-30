bool canAliceWin(int* nums, int n) {
    int dd = 0, sd = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] / 10 != 0) dd += nums[i];
        else sd += nums[i];
    }
    return abs(dd - sd) > 0;
}