class Solution {
public:
    void dfs(vector<int>& vis, int node, vector<int> adj[], int par,
             unordered_map<int, set<int>>& mp, vector<int>& superParent) {
        vis[node] = 1;
        mp[par].insert(node);
        superParent[node] = par;
        for (auto child : adj[node]) {
            if (!vis[child]) {
                dfs(vis, child, adj, par, mp, superParent);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> adj[c + 1];
        for (auto i : connections) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, set<int>> mp;
        vector<int> vis(c + 1, 0);
        vector<int> superParent(c + 1, 0);
        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                dfs(vis, i, adj, i, mp, superParent);
            }
        }
        vector<int> ans;
        vector<int> online(c + 1, 1);
        for (auto i : queries) {
            int type = i[0];
            int node = i[1];
            int par = superParent[node];
            if (type == 1) {
                if (online[node]) {
                    ans.push_back(node);
                } else {
                    if (mp[par].size() > 0) {
                        ans.push_back(*mp[par].begin());
                    } else {
                        ans.push_back(-1);
                    }
                }
            } else {
                online[node] = 0;
                mp[par].erase(node);
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     void dfs(int id, vector<vector<int>>& graph, vector<bool> & vis, int & minId, vector<int> & isOnline){
//         if(vis[id] == true)
//             return;
//         if(isOnline[id] == 1){
//             minId = min(minId, id);
//             // cout << minId << " ";
//         }
//         vis[id] = true;
//         for(auto x: graph[id])
//             dfs(x, graph, vis, minId, isOnline);
//     }
//     vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
//         vector<int> isOnline(c+1, 1);
//         vector<vector<int>> graph(c+1);
//         for(auto x : connections){
//             graph[x[0]].push_back(x[1]);
//             graph[x[1]].push_back(x[0]);
//         }
//         vector<int> ans;
//         for(auto x: queries){
//             if(x[0] == 2)
//                 isOnline[x[1]] = 0;
//             else{
//                 if(isOnline[x[1]] == 1)
//                     ans.push_back(x[1]);
//                 else{
//                     vector<bool> vis(c+1, false);
//                     int minId = INT_MAX;
//                     dfs(x[1], graph, vis, minId, isOnline);
//                     if(minId == INT_MAX)
//                         ans.push_back(-1);
//                     else
//                         ans.push_back(minId);
//                 }
//             }
//         }
//         return ans;
//     }
// };