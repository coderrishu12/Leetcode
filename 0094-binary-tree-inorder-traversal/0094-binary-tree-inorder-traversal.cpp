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
    // void inOrderTraversal(TreeNode* root, vector<int>& ans){
    //     if(!root){
    //         return;
    //     }
    //     inOrderTraversal(root->left, ans);
    //     ans.push_back(root->val);
    //     inOrderTraversal(root->right, ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        stack<TreeNode*> st;
        TreeNode* node=root;

        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }else{
            
            if(st.empty()) break;
            node=st.top();
            st.pop();
            inorder.push_back(node->val);
            node=node->right;
            }
        }
        return inorder;
        // vector<int> ans;
        // inOrderTraversal(root, ans);
        // return ans;
        
    }
};