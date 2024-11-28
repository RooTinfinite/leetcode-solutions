class Log {
public:
    int id;
    bool isStart;
    int time;

    Log(const string& content) {
        size_t pos1 = content.find(":");
        size_t pos2 = content.find(":", pos1 + 1);

        id = stoi(content.substr(0, pos1));
        isStart = content.substr(pos1 + 1, pos2 - pos1 - 1) == "start";
        time = stoi(content.substr(pos2 + 1));
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Log> logsStack;
        vector<int> result(n, 0);

        for (const string& content : logs) {
            Log log(content);
            if (log.isStart) {
                logsStack.push(log);
            } else {
                Log top = logsStack.top();
                logsStack.pop();
                result[top.id] += log.time - top.time + 1;
                if (!logsStack.empty()) {
                    result[logsStack.top().id] -= log.time - top.time + 1;
                }
            }
        }
        return result;
    }
};