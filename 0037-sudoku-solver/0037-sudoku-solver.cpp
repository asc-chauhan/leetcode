class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                        if(isValid(i, j, k, board)){
                            board[i][j] = k;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int r, int c, char digit, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[r][i] == digit)
                return false;
            if(board[i][c] == digit)
                return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == digit)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};