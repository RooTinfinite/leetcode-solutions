var minPrice = function(prices, discounts) {

    prices.sort((a, b) => a - b);
    discounts.sort((a, b) => a - b);

    let p1 = prices.length - 1;
    let p2 = discounts.length - 1;

    let sum = 0;

    while(p1 >= 0 && p2 >= 0){
        sum += prices[p1] * (100 - discounts[p2]) / 100;
        p1--;
        p2--;
    }

    while(p1 >= 0){
        sum += prices[p1];
        p1--;
    }

    return sum;
};