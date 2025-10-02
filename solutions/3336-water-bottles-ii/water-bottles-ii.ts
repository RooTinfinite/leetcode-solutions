function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    let empty = numBottles;
    while (empty >= numExchange) {
        ans++;
        empty -= numExchange - 1;
        numExchange++;
    }
    return ans;
}