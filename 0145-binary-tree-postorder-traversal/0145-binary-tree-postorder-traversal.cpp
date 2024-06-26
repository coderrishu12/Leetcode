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
    // void postOrderTraversal(TreeNode* root, vector<int>& ans){
    //     if(!root){
    //         return;
    //     }
    //     postOrderTraversal(root->left, ans);
    //     postOrderTraversal(root->right, ans);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!=NULL || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
                
            }
        }
        return postorder;
        
        
        
        
//         vector<int> res;
//         if(!root) return res;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* temp=st.top();
//             st.pop();
//             res.push_back(temp->val);
//             if(temp->left) st.push(temp->left);
//             if(temp->right) st.push(temp->right);
//         }
//         reverse(res.begin(), res.end());
//         return res;
        
        
        
        
        
//         vector<int> postorder;
//         if(root==NULL) return postorder;
        
//         stack<TreeNode*> st1, st2;
//         st1.push(root);
//         while(!st1.empty()){
//             root=st1.top();
//             st1.pop();
//             st2.push(root);
            
//             if(root->left) st1.push(root->left);
//             if(root->right) st1.push(root->right);
//         }
//         while(!st2.empty()){
//             postorder.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return postorder;
        
        // vector<int> ans;
        // postOrderTraversal(root, ans);
        // return ans;
    }
};