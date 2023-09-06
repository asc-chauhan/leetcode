class Solution {
public:
    string sortString(string s) {
        string str;
        vector<int> freq(26,0);
        for(int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;
        while(str.size() != s.size()){
            for(int i = 0; i < 26; i++){
                if(freq[i] != 0){
                    str += 'a'+ i;
                    freq[i]--;
                }
            }
            for(int i = 25; i >= 0;i--){
                if(freq[i] != 0){
                    str += 'a'+ i;
                    freq[i]--;
                }
            }
        }
        return str;
    }
};

// class Solution {
// public:
// 	string sortString(string s) {
// 		unordered_map<char, int> mp;
// 		for(auto i : s)
// 			mp[i]++;
// 		string ans = "";
// 		bool found = true;
// 		while(found){
// 			found = false;
// 			for(char c='a' ; c<='z' ; c++){
// 				if(mp[c]){
// 					ans.push_back(c);
// 					mp[c]--;
// 					found= true;
// 				}
// 			}
// 			for(char c='z' ; c>='a' ; c--){
// 				if(mp[c]){
// 					ans.push_back(c);
// 					mp[c]--;
// 					found= true;                    
// 				}
// 			}
// 		}
// 		return ans;
// 	}
// };