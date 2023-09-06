class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = image[i][m-j-1] ^ 1;
            }
        }
        return ans;
    }
};