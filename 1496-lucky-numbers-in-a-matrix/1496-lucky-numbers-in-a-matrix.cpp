class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int k = 0;
            bool t = false;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] < matrix[i][k])
                    k = j;
            }
            for(int j = 0; j < n; j++){
                if(matrix[j][k] > matrix[i][k]){
                    t = true;
                    break;
                }
            }
            if(t == true)
                continue;
            ans.push_back(matrix[i][k]);
        }
        return ans;
    }
};