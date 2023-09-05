class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        //sorts so that we dont need to check between strings.
        //because sort does the work for arranging the strings .
        string a = strs[0];
        string b = strs[n-1];
        //need to compare elements of both strings.
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i])
            {
                ans += a[i];
            }
            else
                break;
        }
        return ans;
    }
};