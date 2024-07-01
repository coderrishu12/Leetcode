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
    void DFS(TreeNode* root, vector<string>& ans, string path){
        if(!root) return;
        
        path+=to_string(root->val);
         if(!root->left && !root->right){
             
            ans.push_back(path);
        }else{
        path+="->";
        DFS(root->left, ans, path);
        DFS(root->right, ans, path);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        DFS(root, ans,"");
        return ans;
    }
};