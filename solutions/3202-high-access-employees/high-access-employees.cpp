
class Solution {
public:
    // Function to find high-access employees based on access times.
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // Create a map to store access times for each employee.
        map<string, vector<int>> when;

        // Populate the map with access times from the input vector.
        for (auto v : access_times) {
            string a = v[0], b = v[1];
            when[a].push_back(stoi(b));
        }

        // Vector to store the names of high-access employees.
        vector<string> ret;

        // Iterate through the map to check access patterns for each employee.
        for (auto &[x, lst] : when) {
            // Sort the access times for each employee.
            sort(begin(lst), end(lst));

            // Get the number of access times for the current employee.
            int k = lst.size();

            // Flag to indicate if the employee is a high-access employee.
            bool flag = false;

            // Check for consecutive accesses within a 100-minute window.
            for (int i = 0; i + 3 <= k; ++i)
                flag |= lst[i + 2] < lst[i] + 100;

            // If the flag is true, the employee is considered high-access, and their name is added to the result.
            if (flag) ret.push_back(x);
        }

        // Return the vector containing the names of high-access employees.
        return ret;
    }
};