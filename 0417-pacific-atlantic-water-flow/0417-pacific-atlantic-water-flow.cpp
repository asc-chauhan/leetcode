class Solution{
public:
    void bfs(const vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int r = cur.first, c = cur.second;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dirs[k][0], nc = c + dirs[k][1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) 
                    continue;
                if (visited[nr][nc]) 
                    continue;
                if (heights[nr][nc] < heights[r][c]) 
                    continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for (int j = 0; j < n; ++j) {
            q.push({0, j});
            pac[0][j] = true;
        }
        for (int i = 1; i < m; ++i) {
            q.push({i, 0});
            pac[i][0] = true;
        }
        bfs(heights, q, pac);
        queue<pair<int,int>> q2;
        for (int j = 0; j < n; ++j) {
            q2.push({m-1, j});
            atl[m-1][j] = true;
        }
        for (int i = 0; i < m-1; ++i) {
            q2.push({i, n-1});
            atl[i][n-1] = true;
        }
        bfs(heights, q2, atl);
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
        return res;
    }
};

// class Solution {
// public:
//     int n, m;
//     void dfs(int x, int y, vector<vector<int>>& h, vector<vector<bool>>& vis) {
//         vis[x][y] = true;
//         vector<int> dx = {1, -1, 0, 0};
//         vector<int> dy = {0, 0, 1, -1};
//         for (int k = 0; k < 4; k++) {
//             int nx = x + dx[k];
//             int ny = y + dy[k];
//             if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
//                 continue;
//             if (vis[nx][ny]) 
//                 continue;
//             if (h[nx][ny] < h[x][y]) 
//                 continue;
//             dfs(nx, ny, h, vis);
//         }
//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
//         n = h.size(), m = h[0].size();
//         vector<vector<bool>> pac(n, vector<bool>(m, false));
//         vector<vector<bool>> atl(n, vector<bool>(m, false));
//         for (int i = 0; i < n; i++) {
//             dfs(i, 0, h, pac);         // Pacific (left)
//             dfs(i, m - 1, h, atl);     // Atlantic (right)
//         }
//         for (int j = 0; j < m; j++) {
//             dfs(0, j, h, pac);         // Pacific (top)
//             dfs(n - 1, j, h, atl);     // Atlantic (bottom)
//         }
//         vector<vector<int>> ans;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (pac[i][j] && atl[i][j])
//                     ans.push_back({i, j});
//             }
//         }
//         return ans;
//     }
// };