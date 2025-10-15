class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 1, inc = 1, prevInc = 0;
        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i])
                inc++;
            else{
                prevInc = inc;
                inc = 1;
            }
            ans = max(ans, inc/2);
            ans = max(ans, min(inc, prevInc));
        }
        return ans;
    }
};