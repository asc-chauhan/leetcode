// moore voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[res] == nums[i])
                count++;
            else
                count--;
            if(count == 0){
                res = i;
                count = 1;
            }            
        }
        return nums[res];
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> m;
//         int maxi;
//         for(int i = 0; i < n; i++){
//             m[nums[i]]++;
//         }
//         for(auto x: m){
//             if(x.second > n/2)
//                 maxi = x.first;
//         }
//         return maxi;
//     }
// };
