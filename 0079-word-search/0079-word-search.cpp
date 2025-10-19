class Solution {
public:
    void dfs(int i, int j, int k, string word, vector<vector<char>>& board, int & flag){
        char ch = board[i][j];
        if(word.size() == k || (word.size() == 1 && ch == word[k])){
            flag = 1;
            return;
        }
        if(flag == 1 || ch != word[k])
            return; 
        board[i][j] = '#';    
        if(i > 0)
            dfs(i-1, j, k+1, word, board, flag);    
        if(i < board.size() - 1)
            dfs(i+1, j, k+1, word, board, flag);  
        if(j > 0)
            dfs(i, j-1, k+1, word, board, flag);  
        if(j < board[0].size()-1)
            dfs(i, j+1, k+1, word, board, flag);      
        board[i][j] = ch;    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int flag = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i, j, 0, word, board, flag);
            }
        }
        return flag==1;
    }
};