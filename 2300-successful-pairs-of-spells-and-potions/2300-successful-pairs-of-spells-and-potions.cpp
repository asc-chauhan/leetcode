class Solution{
public:
    int bs(vector<int> & potions, long long strength, long long success){
        int lo = 0, hi = potions.size()-1, idx = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(1LL*potions[mid]*strength >= success){
                idx = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            int idx = bs(potions, spells[i], success);
            if(idx != -1)
                ans[i] = potions.size() - idx;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end());
//         int n = spells.size();
//         int m = potions.size();
//         vector<int> ans(n, 0);
//         for(int i = 0; i < n; i++){
//             long long s = spells[i];
//             long long need = (success+s-1)/s;
//             auto it = lower_bound(potions.begin(), potions.end(), need);
//             ans[i] = m - int(it - potions.begin());
//         }
//         return ans;
//     }
// };