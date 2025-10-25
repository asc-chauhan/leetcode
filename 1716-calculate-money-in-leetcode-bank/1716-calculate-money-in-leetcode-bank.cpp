class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, mon = 0;
        while(n != 0){
            mon++;
            int cur = mon;
            for(int i = 0; i < 7; i++){
                ans += cur;
                cur++;
                n--;
                if(n == 0)
                    return ans;
            }
        }
        return ans;
    }
};