// TypeScript

function minEnd(n: number, x: number): number {
    // Store available bit positions that are 0 in x
    const shifts: number[] = [];
    
    // Initialize result with starting number x
    let cur = BigInt(x);
    
    // Calculate how many 1's we need to add (n-1)
    let calc = BigInt(n - 1);
    
    // Find all bit positions that are 0 in x (up to 32 bits)
    for(let i = 0; i < 32; i++) {
        if(!((1n << BigInt(i)) & BigInt(x))) {
            shifts.push(i);
        }
    }
    
    // Add remaining positions 32-63 for larger numbers
    for(let i = 32; i < 64; i++) {
        shifts.push(i);
    }
    
    // Process each bit in calc (n-1)
    let i = 0;
    while(calc > 0n) {
        cur += (calc & 1n) << BigInt(shifts[i]);
        calc >>= 1n;
        i++;
    }
    
    return Number(cur);
};