class Solution {
public:
    int find(int a, vector<int>& parent){
        if(parent[a] == a)
            return a;
        else
            return parent[a] = find(parent[a], parent);
    }
    int extra = 0;
    void Union(int a, int b, vector<int>& parent, vector<int>& rank){
        int pa = find(a, parent);
        int pb = find(b, parent);
        if(pa == pb){
            extra++;
            return;
        }
        if(rank[pa] > rank[pb])
            parent[pb] = pa;
        else if(rank[pb] > rank[pa])
            parent[pa] = pb;
        else
            parent[pa] = pb;
            rank[pb]++;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n), rank(n, 0);
        int e = connections.size();
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 0; i < connections.size(); i++)
            Union(connections[i][0], connections[i][1], parent, rank);
        int cc = 0;
        for(int i = 0; i < n; i++){
            if(find(i, parent) == i)
                cc++;
        }
        if(extra < cc-1)
            return -1;
        return cc - 1;
    }
};