class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[j-1]){
                nums[cnt] = nums[j];
                cnt++;
            }
        }
        return cnt;
    }
};