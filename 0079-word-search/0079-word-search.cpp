class Solution {
public:
    void dfs(int id, int r, int c, string word, vector<vector<char>>& board, bool & flag){
        if(id == word.size() || (word.size() == 1 && word[id] == board[r][c])){
            flag = true;
            return;
        }
        if(board[r][c] != word[id])
            return;
        char ch = board[r][c];
        board[r][c] = '#';
        if(r > 0)
            dfs(id+1, r-1, c, word, board, flag);
        if(r < board.size()-1)
            dfs(id+1, r+1, c, word, board, flag);
        if(c > 0)
            dfs(id+1, r, c-1, word, board, flag);
        if(c < board[0].size()-1)
            dfs(id+1, r, c+1, word, board, flag);
        board[r][c] = ch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool flag = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j])
                    dfs(0, i, j, word, board, flag);
                if(flag)
                    return flag;
            }
        }
        return flag;
    }
};