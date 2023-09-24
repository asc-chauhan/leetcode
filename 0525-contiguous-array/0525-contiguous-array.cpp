class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int ans = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
          if(nums[i])
            cnt++;
          else
            cnt--;
          if(mp.find(cnt) != mp.end())
            ans = max(ans,i-mp[cnt]);
          else
            mp[cnt] = i;  
        }
        return ans;
    }
};