class Solution {
public:
    void dfs(vector<string>& curr, string firstEmail, unordered_map<string, int>& vis, unordered_map<string, vector<string>>& mp){
        vis[firstEmail] = 1;
        curr.push_back(firstEmail);
        for(auto x : mp[firstEmail]){
            if(!vis[x])
                dfs(curr, x, vis, mp);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> vis;
        unordered_map<string, vector<string>> mp;
        for(auto x: accounts){
            string firstEmail = x[1];
            for(int i = 2; i < x.size(); i++){
                mp[firstEmail].push_back(x[i]);
                mp[x[i]].push_back(firstEmail);
            }
        }
        vector<vector<string>> ans;
        // Step 2: Perform DFS to collect connected components
        for(auto x: accounts){
            string name = x[0];
            string firstEmail = x[1];
            if(!vis[firstEmail]){
                vector<string> curr;
                curr.push_back(name);
                dfs(curr, firstEmail, vis, mp);
                sort(curr.begin()+1, curr.end());
                ans.push_back(curr);
            }
        }
        return ans;
    }
};