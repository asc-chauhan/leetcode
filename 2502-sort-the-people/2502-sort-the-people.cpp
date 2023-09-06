class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> mp;
        for(int i = 0; i < n; i++)
            mp[heights[i]] = names[i];
        sort(heights.begin(), heights.end(), greater<int>());
        for(int i = 0; i < n; i++){
            names[i] = mp[heights[i]];
        }
        return names;
    }
};

// vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<pair<int, string>> A;
//         int N = names.size();
//         for(int i = 0; i < N; i++) 
//             A.push_back({heights[i], names[i]});
//         sort(A.rbegin(), A.rend());
//         for(int i = 0; i < N; i++) 
// 	        names[i] = A[i].second;
//         return names;
//     }


// vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         priority_queue<pair<int, string>> pq;
//         for(int i = 0; i < heights.size(); i++)
//             pq.push({heights[i], names[i]});
//         vector<string> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
// }