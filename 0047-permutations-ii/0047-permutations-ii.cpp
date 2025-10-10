class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        sort(begin(nums), end(nums));
        generatePermutations(nums, output, 0);
        return output;
    }
private:
    void generatePermutations(vector<int> nums, vector<vector<int>>& output, int idx) {
        if (idx == size(nums)) {
            output.emplace_back(nums);
        }
        for (int i = idx; i < size(nums); ++i) {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            generatePermutations(nums, output, idx + 1);
        }
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