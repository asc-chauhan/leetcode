class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        for(int i = 0; i < n; i++){
            bool t = true;
            for(int j = 0; j < n; j++){
                if(i != j && paths[j][0] == paths[i][1]){
                    t = false;
                    break;
                }
            }
            if(t == true)
                return paths[i][1];
        }
        return paths[0][1];
    }
};

// map 
// string destCity(vector<vector<string>>& paths) {
//         int m = paths.size();
//         unordered_map<string, int> mp;
//         for(int i = 0; i < m; i++)
//            mp[paths[i][0]]++;
//         for(int i = 0; i < m; i++){
//             if(mp[paths[i][1]] < 1)
//                 return paths[i][1];
//         }
//         return "";   
//     }
	
// set
// string destCity(vector<vector<string>>& paths){
// 		unordered_set<string> st;
// 		for(int i = 0; i < paths.size(); i++)
// 			st.insert(paths[i][0]);
// 		for(int i = 0; i < paths.size(); i++){
// 			if(st.find(paths[i][1]) == st.end())
// 				return paths[i][1];
// 		}
//      return "";
//  }		 
	