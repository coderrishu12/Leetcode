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
        if(lefti==-1) return -1;
        int righti= solve(root->right);
        if(righti==-1) return -1;
        if(abs(lefti-righti)>1) return -1;
        return max(lefti,righti)+1;
    }
    bool isBalanced(TreeNode* root) {
//         Approach 2 TC-> O(N), SC->O(N)
        // if(root==NULL) return true;
        return solve(root) !=-1;
        
        
//         Approach 1
//         int diff= abs(solve(root->left)-solve(root->right));
//         if(diff >1) return false;
        
//         bool lefti= isBalanced(root->left);
//         bool righti= isBalanced(root->right);
        
//         if(lefti && righti) return true;
//         return false;
        
        
    }
};