class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == pivot)
                ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > pivot)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};