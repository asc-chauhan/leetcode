class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto x: flights)
            adj[x[0]].push_back({x[1], x[2]});
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({-1,{src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int stops = p.first, cost = p.second.second, node = p.second.first;
            if(stops >= k)
                continue;
            for(auto x: adj[node]){
                if(cost + x.second < dist[x.first]){
                    dist[x.first] = cost + x.second;
                    pq.push({stops+1, {x.first, dist[x.first]}});
                }
            }    
        } 
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};