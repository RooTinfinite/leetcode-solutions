class Solution {
  String reverseVowels(String s) {
    String vowels = 'aeiouAEIOU';
    List<String> sVowels =
        s.split('').reversed.where((char) => vowels.contains(char)).toList();

    List<String> newS =
        s.split('').map((char) => vowels.contains(char) ? '_' : char).toList();

    for (int i = 0, j = 0; i < newS.length; i++) {
      if (newS[i] == '_') {
        newS[i] = sVowels[j];
        j++;
      }
    }

    return newS.join();
  }
}