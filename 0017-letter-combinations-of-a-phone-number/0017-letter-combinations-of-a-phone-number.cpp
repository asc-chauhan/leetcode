class Solution {
public:
    void createMap(unordered_map<int, string>& mp){
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }
    void backtrack(int id, string digits, unordered_map<int, string> mp, vector<string>& ans, string s){
        if(id == digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto x: mp[digits[id] - '0'])
            backtrack(id+1, digits, mp, ans, s+x);
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        createMap(mp);
        vector<string> ans;
        string s = "";
        backtrack(0, digits, mp, ans, s);
        return ans;
    }
};