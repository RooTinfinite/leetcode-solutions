class Solution {
    vector<vector<int>> graph;
    stack<int> st;
    vector<bool> isMemberOfStack;
    vector<int> time;
    vector<int> low;
    int curr_time = 1;
    int ans;
    bool isThereACycleOfLength2;
    vector<vector<int>> cyclesOfLength2;
public:
    
    void dfs(int u, int parent){
        time[u] = curr_time;
        low[u] = curr_time;
        curr_time += 1;
        st.push(u);
        isMemberOfStack[u] = 1;
        
        for(int adj : graph[u]){
            if(time[adj] == 0){  // node is not visited
                dfs(adj, u);
                low[u] = min(low[u], low[adj]);
            }
            if(isMemberOfStack[adj] == 1){
                low[u] = min(low[u], time[adj]);
            }
        }
         
        if(time[u] == low[u]){
            int count = 0;
            while(st.top() != u){
                int v = st.top();
                st.pop();
                isMemberOfStack[v] = 0;
                count += 1;
                // cout<<v<<" ";
            }
            st.pop();
            isMemberOfStack[u] = 0;
            count += 1;
            // cout<<u<<endl;
            
            ans = max(ans , count);
            
            if(count == 2){
                isThereACycleOfLength2 = true;
                vector<int> temp(2,0);
                temp[0] = u;
                temp[1] = graph[u][0];
              
                cyclesOfLength2.push_back(temp);
            }
        }
    }
    
    
    void prepareMaximumLengthsWithoutCycles(vector<int> &maxLen, vector<int> indegree){
        queue<int> q;
        int n = maxLen.size();
        
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.empty() == false){
            int u = q.front();
            q.pop();
            
            for(int v : graph[u]){
                maxLen[v] = max(maxLen[v], 1+ maxLen[u]);
                indegree[v] -= 1;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
    
    }
    

    int maximumInvitations(vector<int>& edges) {
        
        int n = edges.size();
        graph.resize(n);
        time.resize(n);
        low.resize(n);
        isMemberOfStack.resize(n);
        isThereACycleOfLength2 = false;
        vector<int> indegree(n , 0);
        for(int i = 0 ; i < n ; i++){
            
            graph[i].push_back(edges[i]);
            isMemberOfStack[i] = 0;
            time[i] = 0;
            low[i] = 0;
            indegree[edges[i]] += 1;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(time[i] == 0){
                dfs(i, -1);
            }
        }
        
        if(ans == 1){
            return -1;
        }
        
        // if we don't have a cycle of length 2
        if(isThereACycleOfLength2 == false){
            return ans;
        }
        
        
        // if we have cycles of length 2
        
        vector<int> maxLen(n, 1);
        prepareMaximumLengthsWithoutCycles(maxLen, indegree);
        
        
        
        int twonodecyclegraphsanswers = 0;
        for(vector<int> p : cyclesOfLength2 ){
            twonodecyclegraphsanswers += maxLen[p[0]] + maxLen[p[1]] ; 
            ans = max(ans,twonodecyclegraphsanswers );
        }
        
        return ans;
        
        
        
        
        
    }
};