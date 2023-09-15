class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        string ans;
        vector<string> v(numRows);
        int i = 0, n = s.size();
        while(i < n){
            for(int j = 0; j < numRows && i < n; i++, j++)
                v[j] += s[i];
            for(int j = numRows-2; j > 0 && i < n; j--, i++)
                v[j] += s[i];     
        }
        for(int j = 0; j < numRows; j++)
            ans += v[j];
        return ans;    
    }
};