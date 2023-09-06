class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt = 0;
        temp = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1],temp[1]);
                continue;
            }
            else{
                ans.push_back(temp);
                cnt++;
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

//   vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if(intervals.size()<=1) 
//              return intervals;
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> output;
//         output.push_back(intervals[0]);
//         for(int i=1; i<intervals.size(); i++) {
//             if(output.back()[1] >= intervals[i][0]) 
//                  output.back()[1] = max(output.back()[1] , intervals[i][1]);
//             else 
//                  output.push_back(intervals[i]); 
//         }
//         return output;
//     }