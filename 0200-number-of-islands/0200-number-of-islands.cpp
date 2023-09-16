class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int offset[] = {0, 1, 0, -1, 0};
        int cnt = 0;
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
              grid[i][j] = '0';
              cnt++;
              queue<pair<int, int>> q;
              q.push({i,j});
              while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                for(int k = 0; k < 4; k++){
                  int row = p.first + offset[k], col = p.second + offset[k+1];
                  if(row>=0 && row<m && col>=0 && col<n && grid[row][col] == '1'){
                    grid[row][col] = '0';
                    q.push({row, col});
                  }
                }
              }
            }
          }
        }
        return cnt;
    }
};