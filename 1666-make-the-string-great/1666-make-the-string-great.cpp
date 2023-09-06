class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        if(n==0 || n==1)
            return s;
        string ans = "";
        stack<char> st;
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() && abs(st.top() - s[i]) == ('a'-'A'))
                st.pop();
            else
                st.push(s[i]);    
        }     
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};