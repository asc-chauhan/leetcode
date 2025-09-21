class DSU{
    vector<int> p, s;
public:
    DSU(int n, int m){
        p.resize(n+m);
        iota(p.begin(), p.end(), 0);
        s.assign(n+m, 1);
    }
    int Find(int a){
        if(p[a] == a)
            return a;
        return p[a] = Find(p[a]);
    }
    bool Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        if(pa == pb)
            return false;
        if(s[pa] > s[pb]){
            p[pb] = pa;
            s[pa] += s[pb];
            s[pb] = 1;
        }else{
            p[pa] = pb;
            s[pb] += s[pa];
            s[pa] = 1;
        }
        return true;
    }
    int NOC(){
        int cnt = 0;
        for(int i : s){
            if(i > 1)
                cnt++;
        }
        return cnt;
    }
};
class Solution{
public:
    int removeStones(vector<vector<int>>& stones){
        // Step 1: Max row aur col find karo
        int n = 0, m = 0;
        for(auto v : stones){
            n = max(v[0], n);
            m = max(v[1], m);
        }
        DSU ds(n+1, m+1);
        for(auto v : stones){
            int r = v[0];
            int c = v[1] + n + 1;
            ds.Union(r, c);
        }
        return stones.size() - ds.NOC();
    }
};


// class Solution {
// public:
//     void dfs(vector<vector<int>> & stones, int id, vector<bool>& vis, int n){
//         vis[id] = true;
//         for(int i = 0; i < n; i++){
//             if(!vis[i] && (stones[i][0] == stones[id][0] || stones[i][1] == stones[id][1]))
//                 dfs(stones, i, vis, n);
//         }
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         vector<bool> vis(n, 0);
//         int cnt = 0;
//         for(int i = 0; i < n; i++){
//             if(vis[i] == true)
//                 continue;
//             dfs(stones, i, vis, n);
//             cnt++;
//         }
//         return n - cnt;
//     }
// };