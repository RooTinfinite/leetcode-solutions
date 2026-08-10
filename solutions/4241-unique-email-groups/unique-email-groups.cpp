class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {
        set<string> u;
        for (auto e : emails) {
            string domain = e.substr(e.find('@'));
            transform(domain.begin(), domain.end(), domain.begin(),
                      [](unsigned char ch){ return tolower(ch); });
            string name = "";
            for (int i = 0; i < e.size() && e[i] != '+' && e[i] != '@'; i++)
                if (e[i] != '.')
                    name += tolower(e[i]);
            u.insert(name + domain);
        }
        return u.size();
    }
};