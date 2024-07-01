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
    
    bool isSymmetricBoth(TreeNode* left,TreeNode* right){
        if(!left || !right) return left==right;
        
        if(left->val!=right->val) return false;
        
        return isSymmetricBoth(left->left, right->right) && isSymmetricBoth(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
       
        return root==NULL || isSymmetricBoth(root->left, root->right);
    }
};