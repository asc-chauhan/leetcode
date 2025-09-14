class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto x: roads){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;
        pq.push({0, 0});
        int mod = 1e9 + 7;
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(time > dist[node])
                continue;
            for(auto x: adj[node]){
                if(time + x.second < dist[x.first]){
                    dist[x.first] = time + x.second;
                    cnt[x.first] = cnt[node];
                    pq.push({dist[x.first], x.first});
                }
                else if(time + x.second == dist[x.first])
                    cnt[x.first] = (cnt[x.first]+cnt[node])%mod;
            }
        }
        return cnt[n-1];
    }
};