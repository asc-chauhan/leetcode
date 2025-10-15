class Solution{
public:
    void solve(string& s, int id, vector<string>& temp, vector<vector<bool>>& dp, vector<vector<string>>& ans){
        if(id == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = id; i < s.length(); i++){
            if(dp[id][i]){
                temp.push_back(s.substr(id, i - id + 1));
                solve(s, i + 1, temp, dp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n-l+1; i++){
                int j = l + i - 1; // 'j' for the substring s[i...j]
                if(s[i] == s[j]){
                    if(l == 2)  
                        dp[i][j] = true; // base case for length 2
                    else
                        dp[i][j] = dp[i+1][j-1]; // substring s[i+1...j-1] is a palindrome
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, dp, ans);
        return ans;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string & s){
//         int i = 0, j = s.size()-1;
//         while(i <= j){
//             if(s[i] != s[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     void backtrack(int id, vector<string>& pal, vector<vector<string>>& ans, string &s){
//         if(id == s.length()){
//             ans.push_back(pal);
//             return;
//         }
//         for(int i = id; i < s.size(); i++){
//             string part = s.substr(id, i - id + 1);
//             if(isPalindrome(part)){
//                 pal.push_back(part);
//                 backtrack(i + 1, pal, ans, s);
//                 pal.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> palindrome;
//         backtrack(0, palindrome, ans, s);
//         return ans;
//     }
// };