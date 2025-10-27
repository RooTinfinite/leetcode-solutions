function longestPalindrome(s: string): string {
    let sPrime = "#";
    for (let c of s) {
        sPrime += c;
        sPrime += "#";
    }

    let n = sPrime.length;
    let palindromeRadii = new Array(n).fill(0);
    let center = 0;
    let radius = 0;

    for (let i = 0; i < n; i++) {
        let mirror = 2 * center - i;

        if (i < radius)
            palindromeRadii[i] = Math.min(radius - i, palindromeRadii[mirror]);

        while (
            i + 1 + palindromeRadii[i] < n &&
            i - 1 - palindromeRadii[i] >= 0 &&
            sPrime.charAt(i + 1 + palindromeRadii[i]) ==
                sPrime.charAt(i - 1 - palindromeRadii[i])
        )
            palindromeRadii[i]++;

        if (i + palindromeRadii[i] > radius) {
            center = i;
            radius = i + palindromeRadii[i];
        }
    }

    let maxLength = 0;
    let centerIndex = 0;
    for (let i = 0; i < n; i++) {
        if (palindromeRadii[i] > maxLength) {
            maxLength = palindromeRadii[i];
            centerIndex = i;
        }
    }

    let startIndex = Math.floor((centerIndex - maxLength) / 2);
    let longestPalindrome = s.slice(startIndex, startIndex + maxLength);

    return longestPalindrome;
}