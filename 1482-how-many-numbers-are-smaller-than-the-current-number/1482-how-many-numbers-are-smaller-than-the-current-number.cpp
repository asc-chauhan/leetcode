// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i = 0; i < n; i++){
//             int count = 0;
//             for(int j = 0; j < n; j++){
//                 if(nums[j] < nums[i])
//                     count++;
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      unordered_map<int, int > map;
      vector<int> v(nums);
      sort(v.begin(), v.end());
      for(int i = 0; i < v.size() ; i++){
          map.insert({v[i], i});
      }
	  for(int i = 0 ; i < nums.size(); i++){
         v[i] = map[nums[i]];
      }
      return v;
    }
};