/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void DFS(TreeNode* root,  TreeNode* p, TreeNode* q,TreeNode* &ans ){
        if (!root) return;
    
        if (root == p || root == q) {
            ans = root;
            return;
        }

        TreeNode* leftAns = nullptr;
        TreeNode* rightAns = nullptr;
        DFS(root->left, p, q, leftAns);
        DFS(root->right, p, q, rightAns);

        if (leftAns && rightAns) {
            ans = root; 
        } else {
            ans = leftAns ? leftAns : rightAns; 
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        DFS(root, p, q , ans);
        return  ans;
    }
};