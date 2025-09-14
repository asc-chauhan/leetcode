class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto x: times)
            adj[x[0]].push_back({x[1], x[2]});
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int time = p.first, node = p.second;
            for(auto x: adj[node]){
                if(time + x.second < dist[x.first]){
                    dist[x.first] = x.second + time;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};