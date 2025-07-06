class ThroneInheritance {
private:
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(string name, vector<string>& order) {
        if (dead.find(name) == dead.end()) order.push_back(name);
        for (string& child : children[name]) {
            dfs(child, order);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};