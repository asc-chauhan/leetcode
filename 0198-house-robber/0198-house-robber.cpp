class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int dp[n];
//         if(n == 1)
//             return nums[0];
//         dp[0] = nums[0];
//         dp[1] = nums[1];
//         int res = max(dp[0],dp[1]);
//         for(int i = 2; i < n; i++){
//             dp[i] = nums[i];
//             int m = dp[0];
//             for(int j = 0; j < i-1; j++)
//                 m = max(m, dp[j]);
//             dp[i] += m;
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };