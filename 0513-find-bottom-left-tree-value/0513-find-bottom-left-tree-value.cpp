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
public:int maxDepth;
    int bottomLeft;
    void DFS(TreeNode* root, int currDepth){
        if(!root) return ;
        
        if(currDepth>maxDepth){
            maxDepth=currDepth;
            bottomLeft=root->val;
        }
        DFS(root->left, currDepth+1);
        DFS(root->right, currDepth+1);

    }
    int findBottomLeftValue(TreeNode* root) {
//         Approach 1 DFS
        maxDepth=-1;
        DFS(root, 0);
        return bottomLeft;
    }
};