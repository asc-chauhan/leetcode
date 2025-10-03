class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if(m <= 2 || n <= 2)
            return 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < m; i++){
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            vis[i][0] = vis[i][n-1] = 1;
        }
        for(int j = 0; j < n; j++){
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            vis[0][j] = vis[m-1][j] = 1;
        }
        int res = 0;
        vector<int> dir = {1, 0, -1, 0, 1};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int h = curr[0], x = curr[1], y = curr[2];
            for(int k = 0; k < 4; k++){
                int nx = x + dir[k], ny = y + dir[k+1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                if(heightMap[nx][ny] < h)
                    res += h - heightMap[nx][ny];
                pq.push({max(heightMap[nx][ny], h), nx, ny});
            }
        }
        return res;
    }
};