class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> preSum(1000+1, 0);
        for(auto v: trips){
            preSum[v[1]] += v[0];
            preSum[v[2]] -= v[0];
        }
        if(preSum[0] > capacity)
            return false;
        int ans = 0;
        for(int i = 1; i < 1000; i++){
            preSum[i] += preSum[i-1];
            ans = max(preSum[i], ans);
        }
        return ans <= capacity;
    }
};