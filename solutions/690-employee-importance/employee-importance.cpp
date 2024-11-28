class Solution {
public:
    int totalImportance = 0;
    unordered_map<int, Employee*> map;
    
    void checkEmployee(int id) {
        totalImportance += map[id]->importance;
		
        for(int x: map[id]->subordinates) {
            checkEmployee(x);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto x: employees){
            map[x->id] = x;
        }
        
        checkEmployee(id);
        return totalImportance;
    }
};