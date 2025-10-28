class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        long long sum = nums[0];
        leftSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i-1] + nums[i];
            sum += nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && leftSum[i] == sum - leftSum[i])
                ans += 2;
            else if(nums[i] == 0 && abs(leftSum[i]-sum+leftSum[i]) == 1)
                ans += 1;
        }
        return ans;
    }
};