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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, int postStart, int postEnd){
        if(inStart > inEnd) return NULL;
        
        TreeNode* root= new TreeNode(postorder[postEnd]);

        int i = inStart;
        
        for(; i<=inEnd ; i++ ){
            if(inorder[i] == root->val) break;
        }
        
        int leftidx= i-inStart;
        int rightidx= inEnd-i;
        
        root->left  = solve(postorder, inorder, inStart, i-1, postStart , postStart+leftidx-1);
        root->right = solve(postorder, inorder, i+1, inEnd,postEnd-rightidx, postEnd-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        
        int inStart = 0;
        int inEnd   = n-1;
        
        int postStart = 0;
        int postEnd   = n-1;
        
        return solve(postorder, inorder, inStart , inEnd , postStart, postEnd);
    }
};