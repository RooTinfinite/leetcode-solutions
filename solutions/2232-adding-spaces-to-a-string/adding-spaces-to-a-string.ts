// TypeScript

function addSpaces(s: string, spaces: number[]): string {
    const result: string[] = new Array(s.length + spaces.length);
    let writePos: number = 0;
    let readPos: number = 0;
    
    for (const spacePos of spaces) {
        while (readPos < spacePos) {
            result[writePos++] = s[readPos++];
        }
        result[writePos++] = ' ';
    }
    
    while (readPos < s.length) {
        result[writePos++] = s[readPos++];
    }
    
    return result.join('');
}