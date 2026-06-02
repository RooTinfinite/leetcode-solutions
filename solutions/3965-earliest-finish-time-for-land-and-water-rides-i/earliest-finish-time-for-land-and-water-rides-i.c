#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int solve(int* start1, int start1Size, int* duration1, int* start2,
          int start2Size, int* duration2) {
    int finish1 = INT_MAX;
    for (int i = 0; i < start1Size; i++) {
        finish1 = min(finish1, start1[i] + duration1[i]);
    }
    int finish2 = INT_MAX;
    for (int i = 0; i < start2Size; i++) {
        finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
    }
    return finish2;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {
    int land_water = solve(landStartTime, landStartTimeSize, landDuration,
                           waterStartTime, waterStartTimeSize, waterDuration);
    int water_land = solve(waterStartTime, waterStartTimeSize, waterDuration,
                           landStartTime, landStartTimeSize, landDuration);
    return min(land_water, water_land);
}