function minOperations(k: number): number {
    const p = Math.floor(Math.sqrt(k)), q = Math.ceil(k/p); 
    return p + q - 2; 
};