function fizzBuzz(n: number): string[] {
     let res = []
    for (let i = 1; i < n + 1; i++) {  
    if (i % 3 === 0 && i % 5 === 0 ) {
        res.push("FizzBuzz");
    } else if (i % 3 === 0) {
        res.push("Fizz");
    } else if (i % 5 === 0) {
        res.push("Buzz");
    } else {
        res.push(i.toString());
    }
    };
    return res;
};