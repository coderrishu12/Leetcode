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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         Approach 2
        if(!root) return root;
        
        int curr = root->val;
        if(curr > p->val && curr > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(curr < p->val && curr < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
        
        
        
        
//         Approach 1 same as binary tree approach
        
//         if(!root || root==p || root==q) return root;
        
//         TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
//         if(left==NULL) return right;
//         else if(right==NULL) return left;
        
//         return root;
    }
};