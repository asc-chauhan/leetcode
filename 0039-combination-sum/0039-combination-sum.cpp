class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        for(int & x: candidates){
            for(int i = x; i <= target; i++){
                for(auto v: dp[i-x]){
                    v.push_back(x);
                    dp[i].push_back(v);
                }
            }
        }
        return dp[target];
    }
};


// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> combination;
//         vector<vector<int>> ans {};
//         subCombinate(candidates, target, 0, combination, ans);
//         return ans;
//     }
// private:
//     void subCombinate(vector<int>& candidates, int target, int start, vector<int> & combination, vector<vector<int>> & ans){
//         if (target < 0)
//             return;
//         if (target == 0){
//             ans.push_back(combination);
//             return;
//         }
//         for (int i = start; i < candidates.size(); i++){
//             combination.push_back(candidates[i]);
//             subCombinate(candidates, target - candidates[i], i, combination, ans);
//             combination.pop_back();
//         }
//     }
// };


// class Solution {
// public:
//     void findAnswer(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int i, int target){
//         if(target == 0){
//             ans.push_back(temp);
//             return;
//         }
//         if(i == candidates.size() || target - candidates[i] < 0)
//             return;
//         temp.push_back(candidates[i]);
//         findAnswer(candidates, ans, temp, i, target-candidates[i]);
//         temp.pop_back();
//         findAnswer(candidates, ans, temp, i+1, target);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> temp;
//         findAnswer(candidates, ans, temp, 0, target);
//         return ans;
//     }
// };