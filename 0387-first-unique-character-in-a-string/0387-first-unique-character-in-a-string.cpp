class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ump(26);
        for(int i=0; i<s.size(); i++)
            ump[s[i]]++;
         for(int i=0; i<s.size(); i++)
           if(ump[s[i]]==1) return i;
        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int> a(26, 0);
//         int ans = -1;
//         for(auto x : s)
//             a[x - 'a']++;
//         for(int i = 0; i < s.size(); i++){
//             if(a[s[i] - 'a'] == 1)
//                 return i;
//         }    
//         return ans;
//     }
// };