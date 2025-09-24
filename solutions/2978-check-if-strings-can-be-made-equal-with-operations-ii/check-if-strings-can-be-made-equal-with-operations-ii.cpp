class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string even_s1 = "";
          for (int i = 0; i < s1.length(); i += 2) {
            even_s1 += s1[i];
          }

          // Get the string formed by the even indexed characters of s2.
          string even_s2 = "";
          for (int i = 0; i < s2.length(); i += 2) {
            even_s2 += s2[i];
          }

          // Get the string formed by the odd indexed characters of s1.
          string odd_s1 = "";
          for (int i = 1; i < s1.length(); i += 2) {
            odd_s1 += s1[i];
          }

          // Get the string formed by the odd indexed characters of s2.
          string odd_s2 = "";
          for (int i = 1; i < s2.length(); i += 2) {
            odd_s2 += s2[i];
          }
            sort(even_s1.begin(), even_s1.end());
            sort(even_s2.begin(), even_s2.end());
        
            sort(odd_s1.begin(), odd_s1.end());
            sort(odd_s2.begin(), odd_s2.end());
          // If the even and odd indexed strings are equal, then the strings can be made equal.
          return even_s1 == even_s2 && odd_s1 == odd_s2;
    }
};