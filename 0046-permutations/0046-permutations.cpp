class Solution {
public:
    void backtrack(int id, vector<int>& nums, vector<vector<int>>& ans){
        if(id == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = id; i < nums.size(); i++){
            swap(nums[id], nums[i]);
            backtrack(id+1, nums, ans);
            swap(nums[id], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       backtrack(0, nums, ans);
       return ans; 
    }
};