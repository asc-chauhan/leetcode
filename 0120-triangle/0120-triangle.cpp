class Solution{
public:
    int minimumTotal(vector<vector<int>> & triangle){
        int m = triangle.size();
        for(int i = 1; i < m; i++){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1]; 
            for(int j = 1; j < triangle[i].size()-1; j++){
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < triangle[m-1].size(); i++)
            ans = min(ans, triangle[m-1][i]);
        return ans;    
    }
};



// TLE

// class Solution {
// public:
//     int recursion(vector<vector<int>>& triangle, int id, int row, int sum){
//         if(row >= triangle.size())
//             return sum;
//         int k = recursion(triangle, id, row+1, sum+triangle[row][id]);
//         int p = recursion(triangle, id + 1, row+1, sum + triangle[row][id+1]);
//         return  min(k, p); 
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int ans = triangle[0][0];
//         int id = 0;
//         ans = recursion(triangle, id, 1, triangle[0][0]);
//         return ans;
//     }
// };