class Solution{
public:
    void backtrack(int id, int k, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || k <= 0 || id > 9)
            return;
        
        backtrack(id+1, k, target, temp, ans);
        temp.push_back(id);
        backtrack(id+1, k-1, target-id, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(1, k, n, temp, ans);
        return ans;
    }
};

// class Solution {
// public:
//     void backtrack(int id, vector<vector<int>>& ans, vector<int> nums, vector<int>& temp, int k, int target, int sum){
//         if(temp.size() == k && sum == target){
//             ans.push_back(temp);
//             return;
//         }
//         if(temp.size() > k || sum > target || id >= 9)
//             return;
//         backtrack(id+1, ans, nums, temp, k, target, sum);
//         temp.push_back(nums[id]);
//         if(sum + nums[id] <= target)
//             backtrack(id+1, ans, nums, temp, k, target, sum+nums[id]);
//         temp.pop_back();
//     }
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//         vector<int> temp;
//         vector<vector<int>> ans;
//         backtrack(0, ans, nums, temp, k, n, 0);
//         return ans;
//     }
// };