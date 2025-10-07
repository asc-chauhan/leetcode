class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> zeros;
        vector<int> ans(n, 1);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(rains[i] == 0)
                zeros.insert(i);
            else{
                ans[i] = -1;
                if(mp.count(rains[i])){
                    auto x = zeros.lower_bound(mp[rains[i]]);
                    if(x == zeros.end())
                        return {};
                    ans[*x] = rains[i];
                    zeros.erase(x);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};