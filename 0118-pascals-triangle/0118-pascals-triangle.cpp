class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows); // numRows is necessary.
        ans[0].push_back(1);
        for(int i = 1; i < numRows; i++){
            ans[i].push_back(1);
            for(int j = 0; j < i - 1; j++){
                int key = ans[i-1][j] + ans[i-1][j+1];
                ans[i].push_back(key);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};


// vector<vector<int>> generate(int numRows) {
// 	vector<vector<int>> ret;
// 	for (int i = 0; i < numRows; i++) {
// 		vector<int> row(i + 1, 1);
// 		for (int j = 1; j < i; j++) {
// 			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
// 		}
// 		ret.push_back(row);
// 	}
// 	return ret;
// }