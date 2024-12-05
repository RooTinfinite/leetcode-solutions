// TypeScript

function canChange(start: string, target: string): boolean {
    if (start === target) return true;
    let waitL = 0, waitR = 0;
    
    for (let i = 0; i < start.length; i++) {
        const curr = start[i];
        const goal = target[i];
        
        if (curr === 'R') {
            if (waitL > 0) return false;
            waitR++;
        }
        if (goal === 'L') {
            if (waitR > 0) return false;
            waitL++;
        }
        if (goal === 'R') {
            if (waitR === 0) return false;
            waitR--;
        }
        if (curr === 'L') {
            if (waitL === 0) return false;
            waitL--;
        }
    }
    return waitL === 0 && waitR === 0;
}