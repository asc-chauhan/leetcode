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
    vector<int> solve(TreeNode* root, vector<int> res, int lvl){
        if (root==NULL)
            return res;
        if (res.size()==lvl)            // root
            res.push_back(root->val);
        res = solve(root->right , res , lvl + 1);     // right
        res = solve(root->left , res , lvl + 1);       // left
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        res = solve( root , res , 0 );
        return res;
    }
};


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(root == NULL)
//           return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(q.empty() == false){
//           int n = q.size();
//           vector<int> tmp;
//           for(int i = 0; i < n; i++){
//             TreeNode* curr = q.front();
//             q.pop();
//             tmp.push_back(curr->val);
//             if(curr->left)
//               q.push(curr->left);
//             if(curr->right)
//               q.push(curr->right);  
//           }
//           ans.push_back(tmp[n-1]);
//         }
//         return ans;  
//     }
// };