class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n); 
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == end_node)
                return p;
            if(prob[node] > p)
                continue;
            for(auto x: adj[node]){
                if(p*x.second > prob[x.first]){
                    prob[x.first] = p*x.second;
                    pq.push({prob[x.first], x.first});
                }
            }
        }
        return prob[end_node];
    }
};