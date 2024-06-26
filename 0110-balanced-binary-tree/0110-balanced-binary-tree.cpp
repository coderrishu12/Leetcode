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

    
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int lefti= solve(root->left);
        int righti= solve(root->right);
        return 1+max(lefti,righti);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        
        bool lefti= isBalanced(root->left);
        bool righti= isBalanced(root->right);
        bool diff= (abs(solve(root->left)-solve(root->right))<=1);
        // if(diff >1) return false;
        
        if(diff &&lefti && righti) return true;
        return false;
        
        
    }
};