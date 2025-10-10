class Solution{
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void backtrack(int id, vector<int>nums, vector<vector<int>>& ans){
        if(id == nums.size()){
            ans.push_back(nums);
        }
        for(int i = id; i < nums.size(); i++){
            if(i != id && nums[i] == nums[id])
                continue;
            swap(nums[i], nums[id]);
            backtrack(id+1, nums, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, ans);
        return ans; 
    }
};

// O(N! * k * log(k)) --------------- k = unique_permutations
// class Solution {
// public:
//     void swap(int& a, int& b) {
//         int temp = a;
//         a = b;
//         b = temp;
//     }
//     void backtrack(int id, vector<int>& nums, set<vector<int>>& st){
//         if(id == nums.size()){
//             st.insert(nums);
//             return;
//         }
//         for(int i = id; i < nums.size(); i++){
//             if(id != i && nums[id] == nums[i])
//                 continue;
//             swap(nums[id], nums[i]);
//             backtrack(id+1, nums, st);
//             swap(nums[id], nums[i]);
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> st;
//         backtrack(0, nums, st);
//         for(auto x: st)
//             ans.push_back(x);
//         return ans; 
//     }
// };