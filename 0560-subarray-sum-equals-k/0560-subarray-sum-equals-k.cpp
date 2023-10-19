//Solution 01: Prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int preSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            count += mp[remove];
            mp[preSum] += 1;
        }
        return count;
    }
};