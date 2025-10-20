class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        string smallest = s;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr < smallest)
                smallest = curr;
            string add = curr;
            for(int i = 1; i <= add.size(); i += 2)
                add[i] = (add[i]-'0'+a)%10 + '0';
            if(!vis.count(add)){
                vis.insert(add);
                q.push(add);
            }
            string rotate = curr.substr(curr.size()-b) + curr.substr(0, curr.size() - b);
            if(!vis.count(rotate)){
                vis.insert(rotate);
                q.push(rotate);
            }
        }
        return smallest;
    }
};