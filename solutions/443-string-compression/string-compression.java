class Solution {
  public int compress(char[] chars) {
    int ans = 0; // keep track of current position in compressed array

    // iterate through input array using i pointer
    for (int i = 0; i < chars.length;) {
      final char letter = chars[i]; // current character being compressed
      int count = 0; // count of consecutive occurrences of letter

      // count consecutive occurrences of letter in input array
      while (i < chars.length && chars[i] == letter) {
        ++count;
        ++i;
      }

      // write letter to compressed array
      chars[ans++] = letter;

      // if count is greater than 1, write count as string to compressed array
      if (count > 1) {
        // convert count to string and iterate over each character in string
        for (final char c : String.valueOf(count).toCharArray()) {
          chars[ans++] = c;
        }
      }
    }

    // return length of compressed array
    return ans;
  }
}