class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>>& graph, int currNode = 0){
        tmp.push_back(currNode);
        if(currNode == target)
            res.push_back(tmp);
        else{
            for(auto x : graph[currNode])
                dfs(graph, x);
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)  {
        target = graph.size() - 1;
        dfs(graph);
        return res;
    }    
};

// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> ans;
//         int n = graph.size();
//         int s = 0;
//         vector<int> path;
//         path.push_back(s);
//         queue<vector<int>> q;
//         q.push(path);
//         while(!q.empty()){
//             path = q.front();
//             q.pop();
//             int val = path.back();
//             if(val == n-1)
//                 ans.push_back(path);
//             for(auto x: graph[val]){
//                 vector<int> tmp(path);
//                 tmp.push_back(x);
//                 q.push(tmp);
//             }     
//         }
//         return ans;
//     }
// };