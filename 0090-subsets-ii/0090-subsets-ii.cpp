class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        recur(nums, ans, temp, 0);
        return ans;
    }
    void recur(vector<int> nums, vector<vector<int>>& ans, vector<int>& temp, int id){
        ans.push_back(temp);
        for(int i = id; i < nums.size(); i++){
            if(i > id && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            recur(nums, ans, temp, i+1);
            temp.pop_back();    
        }
    }
};