class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int i = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            long long sum = neededTime[i];
            int j = i+1;
            int maxi = neededTime[i];
            while(j < n && colors[j] == colors[i]){
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            if(j != i+1)
                ans += sum - maxi;
            i = j-1;
        }
        return ans;
    }
};