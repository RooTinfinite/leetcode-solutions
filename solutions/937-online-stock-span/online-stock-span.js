var StockSpanner = function() {
    
    // maintain a monotonic stack for stock entry

    // definition of stock entry:
    // first parameter is price quote
    // second parameter is price span
    this.stack = [];  
};


StockSpanner.prototype.next = function(price) {
    
    let [curPrice, curSpan] = [price, 1];
    
    // Compute price span in stock data with monotonic stack
    while( this.stack.length && this.stack[this.stack.length-1].price <= curPrice ){
        
        prev = this.stack.pop();
        let [prevPrice, prevSpan] = [prev.price, prev.span];
        
        // update current price span with history data in stack
        curSpan += prevSpan
    } 
    this.stack.push( {price: curPrice, span:curSpan} );
    
    return curSpan;
};