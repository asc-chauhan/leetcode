class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        if(n == 3)
            return s[0] == s[2];
        int k = n-2;
        while(k--){
            for(int i = 0; i < n-1; i++)
                s[i] = (s[i]-'0' + s[i+1]-'0')%10 + '0';
            n--;
        }
        return s[0] == s[1];
    }
};