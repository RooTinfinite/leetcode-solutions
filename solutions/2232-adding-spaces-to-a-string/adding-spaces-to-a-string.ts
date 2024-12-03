// TypeScript

function addSpaces(s: string, spaces: number[]): string {
    let i = 0, j = 0;
    const res: string[] = [];
    
    while (i < s.length && j < spaces.length) {
        if (i < spaces[j]) {
            res.push(s[i]);
            i++;
        } else {
            res.push(" ");
            j++;
        }
    }
    
    if (i < s.length) {
        res.push(s.slice(i));
    }
    
    return res.join("");
}