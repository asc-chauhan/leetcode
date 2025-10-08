class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            long long s = spells[i];
            long long need = (success+s-1)/s;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans[i] = m - int(it - potions.begin());
        }
        return ans;
    }
};