class Solution{
public:
    int maxFrequency(vector<int> & nums, int k, int ops){
        int mini = INT_MAX, maxi = INT_MIN;
        int ans = 0;
        for(int x: nums){
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        vector<int> freq(maxi+1, 0);
        for(int x: nums)
            freq[x]++;
        for(int i = 1; i <= maxi; i++)
            freq[i] += freq[i-1];
        for(int curr = mini; curr <= maxi; curr++){
            int l = max(mini, curr-k);
            int r = min(maxi, curr+k);
            int f = freq[curr] - freq[curr-1];
            int extra = min(ops, freq[r] - freq[l-1] - f);
            ans = max(ans , f + extra);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k, int numOperations) {
//         unordered_map<int, int> freq;
//         sort(nums.begin(), nums.end());
//         map<int, int> prefix;
//         int l = nums[0] - k, h = nums.back() + k;
//         for(auto x: nums){
//             freq[x]++;
//             prefix[x - k]++;
//             prefix[x + k + 1]--;
//         }
//         int prev = 0, ans = 0;
//         for(int i = l; i <= h; i++){
//             int curr = prefix[i] + prev;
//             ans = max(ans, min(curr, freq[i] + numOperations));
//             prev = curr;
//         }
//         return ans;
//     }
// };