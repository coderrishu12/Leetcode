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
//         Approach 2 with stack
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right=st.top();
            }
                curr->left=NULL;
        }
        
//         Approach 1 
//         if(root==NULL) return ;
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right = prev;
//         root->left  = NULL;
//         prev=root;
        
        
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