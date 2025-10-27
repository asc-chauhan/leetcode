class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int ans = 0;
        int prevCount = 0;
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(bank[i][j] == '1')
                    cnt++;
            }
            if(cnt != 0){
                ans += cnt * prevCount;
                prevCount = cnt;
            }
        }
        return ans;
    }
};