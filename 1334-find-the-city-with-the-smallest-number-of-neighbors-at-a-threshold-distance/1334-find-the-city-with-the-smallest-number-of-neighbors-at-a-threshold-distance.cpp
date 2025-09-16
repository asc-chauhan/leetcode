class Solution {
public:
    void dijkstra(vector<vector<pair<int, int>>>& adj, int src, int n, int distThreshold, vector<int> & count){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto x: adj[node]){
                if(dist[node] + x.second < dist[x.first]){
                    dist[x.first] = dist[node] + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= distThreshold)
                cnt++;
        }
        count[src] = cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> count(n, INT_MAX);
        for(auto x: edges){
            if(x[2] > distanceThreshold)
                continue;
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        for(int i = 0; i < n; i++){
            dijkstra(adj, i, n, distanceThreshold, count);
        }
        int res = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(count[i] <= res){
                ans = i;
                res = count[i];
            }
        }
        return ans;
    }
};