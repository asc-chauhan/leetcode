// class Solution {
// public:
// 	int lengthOfLongestSubstring(string s){
// 		unordered_set<char> set;
// 		int i = 0, j = 0, n = s.size(), ans = 0;
// 		while( i<n && j<n){
// 			if(set.find(s[j]) == set.end()){
// 				set.insert(s[j++]);
// 				ans = max(ans, j-i);
// 			}
// 			else
// 				set.erase(s[i++]); 
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int store[256]={0}; 
        int l=0;     
        int r=0;    
        int ans=0;  
        while(r < s.length()){
            store[s[r]]++;
            while(store[s[r]]>1){ 
                store[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;    
        }  
        return ans;
    }
};