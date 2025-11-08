type TwoSum struct {
    num_counts map[int]int
}

/** Initialize your data structure here. */
func Constructor() TwoSum {
    return TwoSum{num_counts: make(map[int]int)}
}

/** Add the number to an internal data structure..
**/
func (this *TwoSum) Add(number int) {
    if _, ok := this.num_counts[number]; ok {
        this.num_counts[number]++
    } else {
        this.num_counts[number] = 1
    }
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
func (this *TwoSum) Find(value int) bool {
    for num := range this.num_counts {
        complement := value - num
        if complement != num {
            if _, ok := this.num_counts[complement]; ok {
                return true
            }
        } else {
            if this.num_counts[num] > 1 {
                return true
            }
        }
    }
    return false
}