class Solution {
    public int sum(int num1, int num2) {
        return Arrays.stream(new int[]{num1, num2}).sum();
    }
}