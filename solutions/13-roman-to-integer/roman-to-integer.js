// JavaScript

var romanToInt = function(s) {
    const calcScale = (c, a1, a2) => {
        return (c === a1 || c === a2) ? -1 : 1;
    };
    
    let result = 0;
    
    for (let n = 0; n < s.length; n++) {
        const nextChar = s[n + 1] || '';
        
        switch (s[n]) {
            case 'M': result += 1000; break;
            case 'D': result += 500; break;
            case 'C': result += 100 * calcScale(nextChar, 'M', 'D'); break;
            case 'L': result += 50; break;
            case 'X': result += 10 * calcScale(nextChar, 'C', 'L'); break;
            case 'V': result += 5; break;
            case 'I': result += 1 * calcScale(nextChar, 'X', 'V'); break;
        }
    }
    
    return result;
};