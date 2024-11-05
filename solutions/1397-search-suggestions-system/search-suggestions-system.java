class Solution {
    public List<List<String>> suggestedProductsTwoPointer(String[] products, String searchWord) {
        Arrays.sort(products);
        int left = 0;
        int right = products.length - 1;
        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < searchWord.length(); i++) {
            while (left <= right && (i >= products[left].length() || products[left].charAt(i) != searchWord.charAt(i)))
                left++;
            while (left <= right && (i >= products[right].length() || products[right].charAt(i) != searchWord.charAt(i)))
                right--;
            List<String> currentSuggestions = new ArrayList<>();
            for (int j = left; j <= Math.min(right, left + 2); j++)
                currentSuggestions.add(products[j]);
            result.add(currentSuggestions);
        }
        return result;
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        return suggestedProductsTwoPointer(products, searchWord);
    }
}