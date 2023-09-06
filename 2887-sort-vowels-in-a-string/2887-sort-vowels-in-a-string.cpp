class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for(auto x : s){
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
                v.push_back(x); 
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
                s[i] = v[cnt];
                cnt++;
            }
        }
        return s;
    }
};