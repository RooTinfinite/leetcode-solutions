let removeAnagrams = function (words) {
    for (let i = 1; i < words.length;) {
        const countWord = words[i].split('').sort().join();
        const prevWord = words[i - 1].split('').sort().join();
        countWord === prevWord ? words.splice(i, 1) : i++;
    }

    return words;
}