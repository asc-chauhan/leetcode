class Solution {
public:
    int find(int a,vector<int>&parent){
        if(parent[a]==a)return a;
        else return parent[a]=find(parent[a],parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        if (pa == pb) return;  // <-- crucial check, prevents extra rank bump
        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else if (rank[pb] > rank[pa]) {
            parent[pa] = pb;
        } else {
            parent[pa] = pb;
            rank[pb]++;   // increment rank only on first valid merge
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int cc=0; //connected components
        int n=stones.size();
        vector<int>rank(n,1);
        vector<int>parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])Union(i,j,parent,rank);
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i)cc++;
        }
        return n-cc;
    }
};

// class DSU{
//     vector<int> p, s;
// public:
//     DSU(int n, int m){
//         p.resize(n+m);
//         iota(p.begin(), p.end(), 0);
//         s.assign(n+m, 1);
//     }
//     int Find(int a){
//         if(p[a] == a)
//             return a;
//         return p[a] = Find(p[a]);
//     }
//     bool Union(int a, int b){
//         int pa = Find(a);
//         int pb = Find(b);
//         if(pa == pb)
//             return false;
//         if(s[pa] > s[pb]){
//             p[pb] = pa;
//             s[pa] += s[pb];
//             s[pb] = 1;
//         }else{
//             p[pa] = pb;
//             s[pb] += s[pa];
//             s[pa] = 1;
//         }
//         return true;
//     }
//     int NOC(){
//         int cnt = 0;
//         for(int i : s){
//             if(i > 1)
//                 cnt++;
//         }
//         return cnt;
//     }
// };
// class Solution{
// public:
//     int removeStones(vector<vector<int>>& stones){
//         // Step 1: Max row aur col find karo
//         int n = 0, m = 0;
//         for(auto v : stones){
//             n = max(v[0], n);
//             m = max(v[1], m);
//         }
//         DSU ds(n+1, m+1);
//         for(auto v : stones){
//             int r = v[0];
//             int c = v[1] + n + 1;
//             ds.Union(r, c);
//         }
//         return stones.size() - ds.NOC();
//     }
// };


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