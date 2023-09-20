class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int n = nums.size();
        if(nums[0] > nums[1])
            return 0;
        else if(nums[n-1] > nums[n-2])
            return n-1;        
        int lo = 0, hi = nums.size()-1;
        int mid;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] > nums[mid-1])
                lo = mid;
            else
                hi = mid;        
        }
        return mid;
    }
};