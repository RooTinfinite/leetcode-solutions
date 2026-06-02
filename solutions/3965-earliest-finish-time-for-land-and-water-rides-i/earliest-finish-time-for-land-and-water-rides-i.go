func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    solve := func(start1, duration1, start2, duration2 []int) int {
        finish1 := 2147483647
        for i := 0; i < len(start1); i++ {
            if val := start1[i] + duration1[i]; val < finish1 {
                finish1 = val
            }
        }
        finish2 := 2147483647
        for i := 0; i < len(start2); i++ {
            curStart := start2[i]
            if finish1 > curStart {
                curStart = finish1
            }
            if val := curStart + duration2[i]; val < finish2 {
                finish2 = val
            }
        }
        return finish2
    }

    land_water := solve(landStartTime, landDuration, waterStartTime, waterDuration)
    water_land := solve(waterStartTime, waterDuration, landStartTime, landDuration)
    if land_water < water_land {
        return land_water
    }
    return water_land
}