class Solution {
 public:
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }

 private:
  bool check(const string& a, const string& b) {
    for (int i = 0, j = a.length() - 1; i < j; ++i, --j)
      if (a[i] != b[j])
      
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    return true;
  }

  bool isPalindrome(const string& s, int i, int j) {
    while (i < j)
      if (s[i++] != s[j--])
        return false;
    return true;
  }
};