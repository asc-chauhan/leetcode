// class Solution{
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target){
//         vector<vector<vector<int>>> dp(target+1);
//         dp[0] = {{}};
//         for(int & x: candidates){
//             for(int i = x; i <= target; i++){
//                 for(auto v: dp[i-x]){
//                     v.push_back(x);
//                     dp[i].push_back(v);
//                 }
//             }
//         }
//         return dp[target];
//     }
// };

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        backtrack(candidates, target, 0, temp, ans);
        return ans;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int> & temp, vector<vector<int>> & ans){
        if (target < 0)
            return;
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, temp, ans);
            temp.pop_back();
        }
    }
};
