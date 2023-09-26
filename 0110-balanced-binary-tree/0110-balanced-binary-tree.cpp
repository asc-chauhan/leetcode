/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int checkBalanced(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = checkBalanced(root->left);
        int rh = checkBalanced(root->right);
        if(abs(lh-rh)>1 || lh == -1 || rh == -1)
            return -1;
        else
            return max(lh,rh)+1;                
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;    
        return checkBalanced(root) != -1;             
    }
};