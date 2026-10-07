function removeInvalidParentheses(s: string): string[] {
    const isValid = (str: string): boolean => {
        let count = 0;
        for (const char of str) {
            if (char === '(') count++;
            if (char === ')') {
                if (count === 0) return false;
                count--;
            }
        }
        return count === 0;
    };
    
    const result: string[] = [];
    const visited = new Set<string>([s]);
    const queue: string[] = [s];
    let found = false;
    
    while (queue.length > 0) {
        const curr = queue.shift()!;
        
        if (isValid(curr)) {
            result.push(curr);
            found = true;
        }
        
        if (found) continue;
        
        for (let i = 0; i < curr.length; i++) {
            if (curr[i] !== '(' && curr[i] !== ')') continue;
            const nextState = curr.slice(0, i) + curr.slice(i + 1);
            if (!visited.has(nextState)) {
                visited.add(nextState);
                queue.push(nextState);
            }
        }
    }
    return result;
}