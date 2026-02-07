class Solution {
    public String reversePrefix(String s, int k) {
        char[] arr = s.toCharArray();
        
        for (int i = 0; i < k / 2; i++) {
            char temp = arr[i];
            arr[i] = arr[k - 1 - i];
            arr[k - 1 - i] = temp;
        }
        
        return new String(arr);
    }
}