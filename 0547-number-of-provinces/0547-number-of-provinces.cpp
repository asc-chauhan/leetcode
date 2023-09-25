class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n);
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
              cnt++;
              q.push(i);
              while(!q.empty()){
                int j = q.front();
                vis[q.front()] = true;
                q.pop();
                for(int k = 0; k < n; k++){
                  if(isConnected[j][k] == 1 && vis[k]!=1 && k!=j)
                    q.push(k);
                }
              }
            }
        }
        return cnt;
    }
};