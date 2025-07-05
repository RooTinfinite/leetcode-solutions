// orders.length >> customerNamei.length & foodItemi.length
// so it's O(n) in time
func displayTable(orders [][]string) [][]string {
    tablesHash, foodsHash := map[string]int{}, map[string]int{}
    tables, foods := []int{}, []string{}
    for _, o := range orders {
        tablesHash[o[1]] = 0
        foodsHash[o[2]] = 0
    }
    for k := range tablesHash {
        t, _ := strconv.Atoi(k)
        tables = append(tables, t)
    }
    for k := range foodsHash {
        foods = append(foods, k)
    }
    sort.Ints(tables)
    sort.Strings(foods)
    for i, v := range tables {
        tablesHash[strconv.Itoa(v)] = i
    }
    for i, v := range foods {
        foodsHash[v] = i
    }
    result := [][]string{{"Table"}}
    result[0] = append(result[0], foods...)
    pattern := make([]int, len(foods))
    resultInInt := [][]int{}
    for _, v := range tables {
        temp := []int{v}
        temp = append(temp, pattern...)
        resultInInt = append(resultInInt, temp)
    }
    for _, o := range orders {
        resultInInt[tablesHash[o[1]]][foodsHash[o[2]]+1]++
    }
    for i, ri := range resultInInt {
        result = append(result, []string{})
        for _, v := range ri {
            result[i+1] = append(result[i+1], strconv.Itoa(v))
        }
    }
    return result
}