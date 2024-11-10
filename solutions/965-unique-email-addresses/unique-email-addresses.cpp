class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string, string>> uniqueEmails;
        
        for (const string& email : emails) {
            size_t atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos + 1);
            
            size_t plusPos = local.find('+');
            if (plusPos != string::npos) {
                local = local.substr(0, plusPos);
            }
            
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            uniqueEmails.insert({local, domain});
        }
        
        return uniqueEmails.size();
    }
};