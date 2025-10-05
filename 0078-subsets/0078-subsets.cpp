class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector< int>> ans;
        vector<int> sub;
        subset(nums, 0, sub, ans);
        return ans;
    }
    void subset(vector<int>& nums, int i, vector<int> & sub, vector<vector<int>> &ans){
        ans.push_back(sub);
        for(int j = i; j < nums.size(); j++){
            sub.push_back(nums[j]);
            subset(nums, j+1, sub, ans);
            sub.pop_back();
        }
    }
};