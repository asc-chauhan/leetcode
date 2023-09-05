class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int l = 0, h = n-1;
        int cnt = 0;
        while(l <= h){
            if(people[h] + people[l] <= limit){
                h--;
                l++;
                cnt++;
            }
            else{
                h--;
                cnt++;
            }
        }
        return cnt;
    }
};