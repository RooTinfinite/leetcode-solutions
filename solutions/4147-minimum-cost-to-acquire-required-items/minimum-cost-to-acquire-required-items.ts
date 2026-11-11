function minimumCost(
    cost1: number,
    cost2: number,
    costBoth: number,
    need1: number,
    need2: number,
): number {
    let totalCost = 0;

    // Buying separately is cheaper; item 3 is unnecessary
    if (cost1 + cost2 <= costBoth) {
        totalCost = cost1 * need1 + cost2 * need2;
    } else {
        // Buy item 3 first until one requirement is fulfilled
        const cnt_3 = Math.min(need1, need2);
        totalCost = cnt_3 * costBoth;

        need1 -= cnt_3;
        need2 -= cnt_3;

        // Type 1 is still needed; choose the cheaper of items 1 and 3
        if (need1 > 0) {
            totalCost += need1 * Math.min(cost1, costBoth);
            // Type 2 is still needed; choose the cheaper of items 2 and 3
        } else if (need2 > 0) {
            totalCost += need2 * Math.min(cost2, costBoth);
        }
    }

    return totalCost;
}