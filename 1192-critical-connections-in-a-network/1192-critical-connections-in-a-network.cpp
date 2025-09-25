class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<vector<int>>& bridges, vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto x: adj[node]){
            if(x == parent)
                continue;
            if(!vis[x]){
                dfs(x, node, tin, low, vis, bridges, adj);
                low[node] = min(low[node], low[x]);
                if(tin[node] < low[x])
                    bridges.push_back({x, node});
            }
            else
                low[node] = min(low[node], tin[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n], vis(n, 0), tin(n), low(n);
        vector<vector<int>> bridges;
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1, tin, low, vis, bridges, adj);
        return bridges;
    }
};