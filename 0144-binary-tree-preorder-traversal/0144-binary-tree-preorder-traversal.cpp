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
    // Approach 1 by Recursion
    // void preOrderTraversal(TreeNode* root, vector<int>& ans){
    //     if(!root){
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     preOrderTraversal(root->left, ans);
    //     preOrderTraversal(root->right, ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        //    Approach 3 without recursion
         vector<int> preorder;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }else{
                    prev->right = NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
                
         
        
//         Approach 2
//         vector<int> preorder;
//         if(root==NULL) return preorder;
        
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             root=st.top();
//             st.pop();
            
//             preorder.push_back(root->val);
//             if(root->right) st.push(root->right);
//             if(root->left) st.push(root->left);
//         }
//         return preorder;
        
        
        // vector<int> ans;
        // preOrderTraversal(root, ans);
        // return ans;
    
    }
};