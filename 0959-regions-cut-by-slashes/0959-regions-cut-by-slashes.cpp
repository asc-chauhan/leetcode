class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int n = mat.size(), m = mat[0].size();
        int dx[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++){
            int r = i + dx[k], c = j + dx[k+1];
            if(r<0 || r>=n || c<0 || c>=m || mat[r][c]!=0 
            || vis[r][c]) 
                continue;
            dfs(r,c,mat,vis);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3, vector<int> (n*3, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    mat[i*3][j*3 + 2] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        int count = 0;
        vector<vector<int>> vis(n*3, vector<int> (n*3, 0));
        for(int i = 0; i < n*3; i++){
            for(int j = 0; j < n*3; j++){
                if(mat[i][j] == 0 && !vis[i][j]){
                    count++;
                    dfs(i, j, mat, vis);
                }
            }
        }
        return count;
    }
};