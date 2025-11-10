class Solution{
public:
    int minOperations(vector<int> & nums){
        int n = nums.size();
        vector<int> nextSmaller(n, n);
        unordered_map<int, set<int>> mp;
        mp.reserve(n);
        for(int i = 0; i < n; i++)
            mp[nums[i]].insert(i);
        stack<int> st;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(st.size() > 0 && nums[st.top()] >= nums[i])
                st.pop();
            if(st.size() > 0)
                nextSmaller[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                continue;
            int j = nextSmaller[i];
            ans++;
            for(int curr : mp[nums[i]]){
                if(curr >= j)
                    break;
                mp[nums[i]].erase(curr);
                nums[curr] = 0;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int ans = 0;
//         stack<int> st;
//         for(int x: nums){
//             while(!st.empty() && st.top() > x)
//                 st.pop();
//             if(x == 0)
//                 continue;
//             if(st.empty() || st.top() < x){
//                 ans++;
//                 st.push(x);
//             }
//         }
//         return ans;
//     }
// };