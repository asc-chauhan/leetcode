class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Get the number of rows in the matrix
        int n = matrix[0].size(); // Get the number of columns in the matrix
        vector<int> r(m, 1); 
        vector<int> c(n, 1);
        // Traverse the matrix and mark the rows and columns that contain 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    r[i] = 0; // Set the corresponding row value to 0
                    c[j] = 0; // Set the corresponding column value to 0
                }
            }
        }
        // Iterate again and set elements to 0 based on the row and column markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (r[i] == 0 || c[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};


// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         bool flag1 = false, flag2 = false;
//         for(int i=0; i<n; i++){
//             if(matrix[i][0] == 0){
//                 flag1 = true;
//             }
//         }
//         for(int j=0; j<m; j++){
//             if(matrix[0][j] == 0){
//                 flag2 = true;
//             }
//         }
//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     matrix[i][0] = matrix[0][j] = 0;
//                 }
//             }
//         }
//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         if(flag1 == true){
//             for(int i=0; i<n; i++){
//                 matrix[i][0] = 0;
//             }
//         }
//         if(flag2 == true){
//             for(int j=0; j<m; j++){
//                 matrix[0][j] = 0;
//             }
//         }
//     }