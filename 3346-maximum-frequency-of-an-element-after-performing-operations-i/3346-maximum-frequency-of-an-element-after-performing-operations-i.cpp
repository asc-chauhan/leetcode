class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        map<int, int> prefix;
        int l = nums[0] - k, h = nums.back() + k;
        for(auto x: nums){
            freq[x]++;
            prefix[x - k]++;
            prefix[x + k + 1]--;
        }
        int prev = 0, ans = 0;
        for(int i = l; i <= h; i++){
            int curr = prefix[i] + prev;
            ans = max(ans, min(curr, freq[i] + numOperations));
            prev = curr;
        }
        return ans;
    }
};