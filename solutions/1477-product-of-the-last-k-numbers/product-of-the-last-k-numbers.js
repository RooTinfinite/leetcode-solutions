var ProductOfNumbers = function() {
    this.products = [1];
};

ProductOfNumbers.prototype.add = function(num) {
    if (num === 0) {
        this.products = [1];
    } else {
        this.products.push(this.products[this.products.length - 1] * num);
    }
};

ProductOfNumbers.prototype.getProduct = function(k) {
    const n = this.products.length;
    if (k >= n) {
        return 0;
    }
    return Math.trunc(this.products[n - 1] / this.products[n - 1 - k]);
};