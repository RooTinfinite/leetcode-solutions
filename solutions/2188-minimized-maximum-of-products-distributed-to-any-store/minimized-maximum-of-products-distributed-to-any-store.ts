// TypeScript

function minimizedMaximum(n: number, quantities: number[]): number {
    const canDistribute = (x: number): boolean => {
        let stores = 0;
        for (const q of quantities) {
            stores += Math.ceil(q / x);
        }
        return stores <= n;
    };
    
    let left = 1;
    let right = Math.max(...quantities);
    let result = 0;
    
    while (left <= right) {
        const x = Math.floor((left + right) / 2);
        if (canDistribute(x)) {
            result = x;
            right = x - 1;
        } else {
            left = x + 1;
        }
    }
    
    return result;
}