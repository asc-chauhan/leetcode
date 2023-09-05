// Kadane
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = nums[0];
//         int maxEnd = nums[0];
//         int n = nums.size();
//         for(int i = 1; i < n; i++){
//             maxEnd = max(maxEnd + nums[i], nums[i]);
//             res = max(res,maxEnd);
//         }
//         return res;
//     }
// };


// Dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }
};