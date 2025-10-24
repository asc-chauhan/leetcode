class Solution{
public:
    int maxFrequency(vector<int> & nums, int k, int numOperations){
        unordered_map<int, int> ranges;
        unordered_map<int, int> freq;
        set<int> points;
        int preSum = 0;
        for(auto x: nums){
            freq[x]++;
            ranges[x-k]++;
            ranges[x+k+1]--;
            points.insert(x);
            points.insert(x-k); // left
            points.insert(x+k+1); // right + 1
        }
        int ans = 1;
        for(auto x: points){
            preSum += ranges[x];
            int extra = min(numOperations, preSum - freq[x]);
            ans = max(ans, extra + freq[x]);
        }
        return ans;
    }
};

// Memory Limit exceeded
// class Solution{
// public:
//     int maxFrequency(vector<int> & nums, int k, int numOperations){
//         int n = nums.size();
//         int mini = INT_MAX, maxi = INT_MIN;
//         int ans = 0;
//         for(auto x: nums){
//             mini = min(mini, x);
//             maxi = max(maxi, x);
//         }
//         vector<int> freq(maxi+1, 0);
//         for(auto x: nums)
//             freq[x]++;
//         for(int i = 1; i <= maxi; i++)
//             freq[i] += freq[i-1];
//         for(int curr = mini; curr <= maxi; curr++){
//             int l = max(mini, curr - k);
//             int r = min(maxi, curr + k);
//             int currFreq = freq[curr] - freq[curr-1];
//             // deleting freq of the curr from extra because we are trying to reach this curr
//             int extra = min(numOperations, freq[r] - freq[l-1] - currFreq);
//             ans = max(ans, extra + currFreq);
//         }
//         return ans;
//     }
// };

