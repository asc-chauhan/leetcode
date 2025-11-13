class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> cntOnes(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                cnt++;
            else
                cntOnes[i] = cnt;
            cout << cntOnes[i] << " ";
        }
        for(int i = n-1; i > 0; i--){
            if(s[i] == '0' && s[i-1] == '1')
                ans += cntOnes[i];
        }
        return ans;
    }
};