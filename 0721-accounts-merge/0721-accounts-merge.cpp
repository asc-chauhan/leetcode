class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int xp = find(x), yp = find(y);
        if(xp == yp)
            return;
        if(size[xp] > size[yp]){
            size[xp] += size[yp];
            parent[yp] = xp;
        }
        else{
            size[yp] += size[xp];
            parent[xp] = yp;
        }
    }
};
class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        unordered_map<string, int> mp;
        int n = accounts.size();
        Disjoint ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    ds.Union(mp[mail], i);
            }
        }
        unordered_map<int, vector<string>> merged;
        for(auto x: mp){
            int parent = ds.find(x.second);
            merged[parent].push_back(x.first);
        }
        vector<vector<string>> res;
        for(auto x: merged){
            vector<string> temp;
            temp.push_back(accounts[x.first][0]);
            sort(x.second.begin(), x.second.end());
            temp.insert(temp.end(), x.second.begin(),x.second.end());
            res.push_back(temp);
        }
        return res;
    }
};

// class Solution {
// public:
//     void dfs(vector<string>& curr, string firstEmail, unordered_map<string, int>& vis, unordered_map<string, vector<string>>& mp){
//         vis[firstEmail] = 1;
//         curr.push_back(firstEmail);
//         for(auto x : mp[firstEmail]){
//             if(!vis[x])
//                 dfs(curr, x, vis, mp);
//         }
//     }
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         unordered_map<string, int> vis;
//         unordered_map<string, vector<string>> mp;
//         for(auto x: accounts){
//             string firstEmail = x[1];
//             for(int i = 2; i < x.size(); i++){
//                 mp[firstEmail].push_back(x[i]);
//                 mp[x[i]].push_back(firstEmail);
//             }
//         }
//         vector<vector<string>> ans;
//         // Step 2: Perform DFS to collect connected components
//         for(auto x: accounts){
//             string name = x[0];
//             string firstEmail = x[1];
//             if(!vis[firstEmail]){
//                 vector<string> curr;
//                 curr.push_back(name);
//                 dfs(curr, firstEmail, vis, mp);
//                 sort(curr.begin()+1, curr.end());
//                 ans.push_back(curr);
//             }
//         }
//         return ans;
//     }
// };