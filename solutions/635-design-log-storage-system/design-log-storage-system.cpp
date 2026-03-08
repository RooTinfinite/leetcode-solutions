class LogSystem {
public:
    LogSystem() { }

    void put(int id, string time) {
        logs.emplace(time, id);
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int> ids;
        int el = lengths[gra]; // effective length
        string es = s.substr(0, el); // effective start time string, eg.: 2017:01:01
        string ee = e.substr(0, el); // effective end time string, eg.: 2017:01:02

        for (auto it = logs.begin(); it != logs.end(); it++) {
            string time = it->first; // 2017:01:01:23:59:59
            int id = it->second;
            string etime = time.substr(0, el);
            if (es <= etime && etime <= ee) {
                ids.push_back(id);
            }
        }
        return ids;
    }

private:
    multimap<string, int> logs;

    // effective lengths of time stamps for different granularity
    map<string, int> lengths{ { "Year", 4 },{ "Month", 7 },{ "Day", 10 },{ "Hour", 13 },{ "Minute", 16 },{ "Second", 19 } };
};