class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> h;
        for(auto x : arr)
            h[x]++;
        unordered_set<int> s;
        for(auto x:h){
            s.insert(x.second);
        }    
        if(s.size() == h.size())
            return true;
        else
            return false;    
    }
};