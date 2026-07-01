class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (string& d : dictionary) {
			int n = d.length();
			string abbr = d[0] + to_string(n) + d[n - 1];
			mp[abbr].insert(d);
		}
	}

	bool isUnique(string word) {
		int n = word.length();
		string abbr = word[0] + to_string(n) + word[n - 1];
		return mp[abbr].count(word) == mp[abbr].size(); 
	}
private:
	unordered_map<string, unordered_set<string>> mp;
};
 
 
// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");