func findChampion(n int, edges [][]int) int {
    incoming := make([]int, n)
    
    for _, edge := range edges {
        incoming[edge[1]]++
    }
    
    champions := []int{}
    for i, count := range incoming {
        if count == 0 {
            champions = append(champions, i)
        }
    }
    
    if len(champions) > 1 {
        return -1
    }
    
    return champions[0]
}