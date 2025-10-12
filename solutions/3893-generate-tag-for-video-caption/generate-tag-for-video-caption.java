class Solution {
    public String generateTag(String s) {
        String[] a = s.split(" ");
        StringBuilder sb = new StringBuilder();
        sb.append("#");
        boolean isFirstWord = true;
        for (String word : a) {
            word = word.replaceAll("[^a-zA-Z]", "");
            if (word.isEmpty()) continue;
            word = word.toLowerCase();
            char firstChar = word.charAt(0);
            String rest = word.substring(1);
            if (isFirstWord) {
                sb.append(firstChar).append(rest);
                isFirstWord = false;
            } else {
                sb.append(Character.toUpperCase(firstChar)).append(rest);
            }
        }
        return sb.length() > 100 ? sb.substring(0, 100) : sb.toString();
    }
}