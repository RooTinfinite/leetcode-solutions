class Solution {

    public List<String> generateAbbreviations(String word) {
        int N = word.length();
        List<String> abbreviations = new ArrayList<>();

        for (int mask = 0; mask < (1 << N); mask++) {
            StringBuilder currWord = new StringBuilder();
            int abbreviatedCount = 0;

            for (int index = 0; index < N; index++) {
                // If the bit at position index is 1, increment the abbreviated substring.
                if ((mask & (1 << index)) != 0) {
                    abbreviatedCount++;
                } else {
                    // Append the last substring and then the current character.
                    if (abbreviatedCount > 0) {
                        currWord.append(abbreviatedCount);
                        abbreviatedCount = 0;
                    }
                    currWord.append(word.charAt(index));
                }
            }

            if (abbreviatedCount > 0) {
                currWord.append(abbreviatedCount);
            }
            abbreviations.add(currWord.toString());
        }

        return abbreviations;
    }
}