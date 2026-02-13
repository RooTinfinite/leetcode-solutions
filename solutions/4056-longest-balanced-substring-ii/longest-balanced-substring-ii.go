func longestBalanced(s string) int {
    results := []int{
        solve1(s, 'a'),
        solve1(s, 'b'),
        solve1(s, 'c'),
        solve2(s, 'a', 'b'),
        solve2(s, 'a', 'c'),
        solve2(s, 'b', 'c'),
        solve3(s),
    }
    ans := 0
    for _, v := range results {
        if v > ans {
            ans = v
        }
    }
    return ans
}

func solve1(s string, t byte) int {
    result := 0
    count := 0
    for i := 0; i < len(s); i++ {
        c := s[i]
        if c == t {
            count++
            if count > result {
                result = count
            }
        } else {
            count = 0
        }
    }
    return result
}

func solve2(s string, t1 byte, t2 byte) int {
    result := 0
    c0 := 0
    c1 := 0
    previous := map[int]int{}
    for i := 0; i < len(s); i++ {
        c := s[i]
        if c != t1 && c != t2 {
            previous = map[int]int{}
            c0 = 0
            c1 = 0
        } else {
            if c == t1 {
                c0++
            } else {
                c1++
            }
            if c0 == c1 {
                v := c0 * 2
                if v > result {
                    result = v
                }
            } else {
                diff := c0 - c1
                if prev, ok := previous[diff]; ok {
                    v := i - prev
                    if v > result {
                        result = v
                    }
                } else {
                    previous[diff] = i
                }
            }
        }
    }
    return result
}

func solve3(s string) int {
    result := 0
    ca, cb, cc := 0, 0, 0
    previous := map[int64]int{}
    for i := 0; i < len(s); i++ {
        switch s[i] {
        case 'a':
            ca++
        case 'b':
            cb++
        default:
            cc++
        }
        if ca == cb && cb == cc {
            result = i + 1
        } else {
            diff := int64(ca-cb)*100001 + int64(cb-cc)
            if prev, ok := previous[diff]; ok {
                v := i - prev
                if v > result {
                    result = v
                }
            } else {
                previous[diff] = i
            }
        }
    }
    return result
}