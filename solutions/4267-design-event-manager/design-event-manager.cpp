class EventManager {
public:
    set<pair<int, int>> s; // {priority, eventId}
    unordered_map<int, int> umap; // {eventId, priority}
    
    EventManager(vector<vector<int>>& events) {
        for (auto &it: events) {
            s.insert({it[1], -it[0]});
            umap[it[0]] = it[1];
        }
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        int p = umap[eventId];
        s.erase({p, -eventId});
        
        umap[eventId] = newPriority;
        s.insert({newPriority, -eventId});
    }
    
    int pollHighest() {
        if (s.empty()) return -1;
        
        auto it = prev(s.end());
        auto [p, e] = *it;
        s.erase(it);

        return -e;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */