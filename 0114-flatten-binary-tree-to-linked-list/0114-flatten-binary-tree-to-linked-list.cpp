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
public:TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
//         Approach 1 
        if(root==NULL) return ;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left  = NULL;
        prev=root;
        
        
//         Approach 3 TC->O(n) SC->O(1)
//         TreeNode* curr = root;
//         while(curr!=NULL){
//             if(curr->left!=NULL){
//                 TreeNode* prev = curr->left;
//                 while(prev->right){
//                     prev=prev->right;
//                 }
//                 prev->right = curr->right;
//                 curr->right = curr->left;
//                 curr->left = nullptr;
//             }
//             curr=curr->right;
//         }
        
    }
};