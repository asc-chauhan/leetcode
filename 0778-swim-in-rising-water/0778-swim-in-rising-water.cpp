class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>vis (n, vector<int>(n,0));
        pq.push({grid[0][0], {0, 0}});
        int ans = 0;
        vector<int> dx = {0, -1, 0, 1, 0};
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int t = p.first;
            int r = p.second.first;
            int c = p.second.second;
            if(r == n-1 && c == n-1)
                return t;
            for(int i = 0; i < 4; i++){
                int x = r + dx[i];
                int y = c + dx[i+1];
                if(x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0){
                    vis[x][y] = 1;
                    pq.push({max(t, grid[x][y]), {x, y}});
                }
            }    
        }
        return ans;
    }
};