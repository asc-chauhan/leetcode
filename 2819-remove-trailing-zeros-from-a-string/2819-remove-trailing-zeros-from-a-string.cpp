class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        string ans;
        for(int i = n-1; i >= 0; i--){
            if(num[i] == '0')
                n--;
            else
                break;    
        }
        for(int i = 0; i < n; i++){
            ans += num[i];
        }
        return ans;
    }
};