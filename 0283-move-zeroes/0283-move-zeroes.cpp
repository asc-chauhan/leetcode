class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(j < n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==0 && nums[j]==0){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             if(nums[i] != 0){
//                 swap(nums[i],nums[count]);
//                 count++;
//             }
//         }
//     }
// };