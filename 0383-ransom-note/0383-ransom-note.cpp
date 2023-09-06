class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto x : magazine)
            mp[x]++;
        for(auto x : ransomNote){
            mp[x]--;
            if(mp[x] == -1)
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         int freq[26]={0};
//         for(int i=0;i<magazine.size();i++){
//             freq[int(magazine[i])-97]++;
//         }
//         for(int i=0;i<ransomNote.size();i++){
//             freq[int(ransomNote[i])-97]--;
//         }
//         for(int i=0;i<26;i++){
//             if(freq[i]<0)
//                 return false;
//         }
//         return true;
//     }
// };