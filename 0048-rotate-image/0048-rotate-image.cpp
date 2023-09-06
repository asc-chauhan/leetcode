// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans[n][n];
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 ans[i][n-j-1] = matrix[i][j];
//             }
//         }
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 matrix[i][j] = ans[i][j];
//             }
//         }
//     }
// };

// transpose and then reverse each row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};