class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = t.size();
        while(i < n && j < m){
            if(t[j] == s[i]){
                i++;
                j++;
            }
            else
                j++;
        }
        if(i < n && j >= m)
            return false;
        else
            return true;    
    }
};

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         deque<char> container;
//         for (auto c: s){
//             container.push_back(c);
//         }
//        for (char ch: t){
//            if(ch == container.front()){
//                container.pop_front();
//            }
//        }
//        return container.empty(); 
//     }
// };