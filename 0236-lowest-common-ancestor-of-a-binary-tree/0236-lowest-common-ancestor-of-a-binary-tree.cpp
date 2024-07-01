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
        //Approach 2
        if(root==NULL || root==p || root==q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
        
        
        //Approach 1
        // TreeNode* ans=nullptr;
        // DFS(root, p, q , ans);
        // return  ans;
    }
};