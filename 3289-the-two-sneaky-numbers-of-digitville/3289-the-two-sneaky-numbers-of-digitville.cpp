class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans(2);
        int XOR = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            XOR ^= nums[i];
        for(int i = 0; i < n-2; i++)
            XOR ^= i;
        int a = 0, b = 0;
        int diffBit = XOR & -XOR;
        for(int i = 0; i < n; i++){
            if((diffBit & nums[i]) == 0)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        for(int i = 0; i < n - 2; i++){
            if((diffBit & i) == 0)
                a ^= i;
            else
                b ^= i;
        }
        ans[0] = a, ans[1] = b;
        return ans;
    }
};