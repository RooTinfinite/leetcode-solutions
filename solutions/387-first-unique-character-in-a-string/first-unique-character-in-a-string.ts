// TypeScript

function firstUniqChar(inputStr: string): number {
    let firstUnique: number = Infinity;
    
    for (let charCode = 'a'.charCodeAt(0); charCode <= 'z'.charCodeAt(0); charCode++) {
        const currChar = String.fromCharCode(charCode);
        
        if (inputStr.includes(currChar)) {
            if (inputStr.indexOf(currChar) === inputStr.lastIndexOf(currChar)) {
                firstUnique = Math.min(firstUnique, inputStr.indexOf(currChar));
            }
        }
    }
    
    return firstUnique !== Infinity ? firstUnique : -1;
}