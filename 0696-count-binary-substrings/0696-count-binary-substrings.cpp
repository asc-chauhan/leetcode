class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,ans=0,curr=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i])
                curr++;
            else{
                ans+=min(curr,prev);     
                prev=curr;
                curr=1;
            }
        }
        ans+=min(prev,curr);
        return ans;
    }
};