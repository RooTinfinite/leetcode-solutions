package main

func numIdenticalPairs(A []int) int {
    ans := 0
    cnt := make(map[int]int)
    
    for _, x := range A {
        ans += cnt[x]
        cnt[x]++
    }
    
    return ans
}
