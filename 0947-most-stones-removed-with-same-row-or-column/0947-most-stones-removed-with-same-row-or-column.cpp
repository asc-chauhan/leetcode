class Solution {
public:
    int dfs(vector<vector<int>> & stones, int id, vector<bool>& vis, int n){
        vis[id] = true;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (stones[i][0] == stones[id][0] || stones[i][1] == stones[id][1]))
                res += dfs(stones, i, vis, n) + 1;
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == true)
                continue;
            ans += dfs(stones, i, vis, n);
        }
        return ans;
    }
};