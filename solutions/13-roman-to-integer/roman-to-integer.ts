// TypeScript

function romanToInt(s: string): number {
    const roman: { [key: string]: number } = {
        'I': 1, 'V': 5, 'X': 10,
        'L': 50, 'C': 100, 'D': 500, 'M': 1000
    };
    
    const n: number = s.length;
    let result: number = roman[s[n-1]];
    
    for(let i = n-2; i >= 0; i--) {
        if(roman[s[i]] < roman[s[i+1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    
    return result;
}