class Solution{
public:
    int triangularSum(vector<int>& nums){
        int n = nums.size();
        for(int size = n; size > 1; size--){
            for(int i = 0; i < size-1; i++)
                nums[i] = (nums[i]+nums[i+1])%10;
        }
        return nums[0];
    }
};

// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return nums[0];
//         vector<int> v;
//         for(int i = 0; i < n-1; i++)
//             v.push_back((nums[i] + nums[i+1])%10);
//         return triangularSum(v);
//     }
// };