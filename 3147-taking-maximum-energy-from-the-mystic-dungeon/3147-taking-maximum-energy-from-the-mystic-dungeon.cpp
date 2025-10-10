class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN, n = energy.size();
        vector<int>preSum(energy.size(), 0);
        for(int i = 0; i < k; i++){
            preSum[i] = energy[i];
        }
        for(int i = k; i < n; i++)
            preSum[i] = max(energy[i], preSum[i-k] + energy[i]);
        for(int i = n-1; i > n - k - 1; i--)
            ans = max(ans, preSum[i]);
        return ans;
    }
};