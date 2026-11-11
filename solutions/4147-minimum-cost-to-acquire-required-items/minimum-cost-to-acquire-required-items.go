func minimumCost(cost1 int, cost2 int, costBoth int, need1 int, need2 int) int64 {
	var totalCost int64 = 0

	// Buying separately is cheaper; item 3 is unnecessary
	if cost1+cost2 <= costBoth {
		totalCost = int64(cost1)*int64(need1) + int64(cost2)*int64(need2)
	} else {
		// Buy item 3 first until one requirement is fulfilled
		cnt3 := min(need1, need2)
		totalCost = int64(cnt3) * int64(costBoth)

		need1 -= cnt3
		need2 -= cnt3

		// Type 1 is still needed; choose the cheaper of items 1 and 3
		if need1 > 0 {
			totalCost += int64(need1) * int64(min(cost1, costBoth))
		} else if need2 > 0 {
			// Type 2 is still needed; choose the cheaper of items 2 and 3
			totalCost += int64(need2) * int64(min(cost2, costBoth))
		}
	}

	return totalCost
}