class Solution {
public:
    bool isPalindrome(string & s){
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int id, vector<string>& pal, vector<vector<string>>& ans, string &s){
        if(id == s.length()){
            ans.push_back(pal);
            return;
        }
        for(int i = id; i < s.size(); i++){
            string part = s.substr(id, i - id + 1);
            if(isPalindrome(part)){
                pal.push_back(part);
                backtrack(i + 1, pal, ans, s);
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindrome;
        backtrack(0, palindrome, ans, s);
        return ans;
    }
};