class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0, j = 1;
        for(auto num : nums){
            if(num > 0){
                ans[i] = num;
                i += 2;
            }
            else if(num < 0){
                ans[j] = num;
                j += 2;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pos, neg;
//         for(auto x : nums){
//             if(x < 0)
//                 neg.push_back(x);
//             else
//                 pos.push_back(x);    
//         }
//         for(int i = 0; i < n; i++){
//             if(i%2 == 0)
//                 nums[i] = pos[i/2];
//             else
//                 nums[i] = neg[i/2];    
//         }
//         return nums;
//     }
// };