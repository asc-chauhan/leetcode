class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
       
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
        return {-1, -1};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>vect;
//         int n=nums.size();
//         vector<pair<int,int>>mp;
//         for(int i=0;i<n;i++){
//             mp.push_back({nums[i],i});
//         }
//         sort(mp.begin(),mp.end());
//         int i=0,j=n-1;
//         while(i<j){
//             if(mp[i].first+mp[j].first==target){
//                 vect.push_back(mp[i].second);
//                 vect.push_back(mp[j].second);
//                 break;
//             }
//             else if(mp[i].first+mp[j].first>target){
//                 j--;
//             }
//             else{
//                 i++;
//             }
//         }
//         return vect;
//     }
// };



// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         for(int i = 0; i < nums.size() - 1;i++){
//             int a = 0;
//             for(int j = i+1; j < nums.size();j++){
//                 if(nums[i] + nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     a = 1;
//                     break;
//                 }
//             }
//             if(a == 1){
//                 break;
//             }                
//         }
//         return ans;
//     }
// };