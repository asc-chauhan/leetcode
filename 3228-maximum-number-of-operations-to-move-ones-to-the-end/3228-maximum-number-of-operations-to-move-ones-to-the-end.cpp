class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                cnt++;
            else if(i > 0  &&  s[i-1] == '1')
                ans += cnt;
            // cout << cntOnes[i] << " ";
        }
        return ans;
    }
};