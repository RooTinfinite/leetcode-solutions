class Solution {
    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return new ArrayList(Arrays.asList(""));
        }

        List<String> answer = new ArrayList();
        for (
            int leftCount = 0;
            leftCount < n;
            ++leftCount
        ) for (String leftString : generateParenthesis(
            leftCount
        )) for (String rightString : generateParenthesis(
            n - 1 - leftCount
        )) answer.add("(" + leftString + ")" + rightString);
        return answer;
    }
}