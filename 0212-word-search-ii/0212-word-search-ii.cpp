class Solution {
    struct TrieNode{
        TrieNode* children[26];
        string word;
        TrieNode(): word(""){
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
    TrieNode* buildTrie(vector<string> &words){
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            TrieNode* curr = root;
            for(int j = 0; j < s.length(); j++){
                char c = s[j] - 'a';
                if(curr->children[c] == NULL)
                    curr->children[c] = new TrieNode();
                curr = curr->children[c];    
            }
            curr->word = s;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& ans){
        char c = board[i][j];
        if(c == '#' || !p->children[c-'a'])
            return;
        p = p->children[c-'a'];
        if(p->word.size() > 0){
            ans.push_back(p->word);
            p->word = "";
        }    
        board[i][j] = '#';
        if(i > 0)
            dfs(board, i-1, j, p, ans);
        if(j > 0)
            dfs(board, i, j-1, p, ans);
        if(i < board.size() - 1)
            dfs(board, i + 1, j, p, ans);
        if(j < board[0].size() -1)
            dfs(board, i, j+1, p, ans);
        board[i][j] = c;                
    }
};