class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        ans = (high-low)/2;
        if(low%2 != 0 || high%2 != 0)
            ans++;
        return ans;    
    }
};

// class Solution {
// public:
//     int countOdds(int l, int h) {
//         return ((h + 1) / 2) - (l / 2);
//     }
// };