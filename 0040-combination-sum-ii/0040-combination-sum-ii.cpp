class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector< set<vector<int>> > dp(target + 1);
        dp[0].insert(vector<int>());
        for (int num : candidates) {
            for (int t = target; t >= num; --t) {
                for (auto comb : dp[t - num]) {
                    vector<int> newComb = comb;
                    newComb.push_back(num);
                    dp[t].insert(newComb); // set dedupes
                }
            }
        }
        // move set contents to vector
        vector<vector<int>> res;
        for (auto &comb : dp[target]) 
            res.push_back(comb);
        return res;
    }
};

// here until i have same element skip index while loop
// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> path;
//         backtrack(candidates, 0, target, path, ans);
//         return ans;
//     }

//     void backtrack(vector<int>& arr, int idx, int remain, vector<int>& path, vector<vector<int>>& ans) {
//         if (remain == 0) {
//             ans.push_back(path);
//             return;
//         }
//         if (remain < 0 || idx == arr.size()) 
//             return;
//         // take arr[idx]
//         path.push_back(arr[idx]);
//         backtrack(arr, idx + 1, remain - arr[idx], path, ans);
//         path.pop_back();
//         // skip duplicates
//         int next = idx + 1;
//         while (next < arr.size() && arr[next] == arr[idx]) 
//             next++;
//         backtrack(arr, next, remain, path, ans);
//     }
// };