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
    int result=INT_MIN;
    int solve(TreeNode* root, int start){
        if(root==NULL) return 0;
        
        int leftH  = solve(root->left, start);
        int rightH = solve(root->right, start);
        
        if(root->val==start){
            result=max(leftH, rightH);
            return -1;
        }
        if(leftH>=0 && rightH>=0){
            return max(leftH, rightH) +1;
        }else{
            int d= abs(leftH)+abs(rightH);
            result=max(result, d);
            return min(leftH, rightH) -1;
        }
     return 0;   
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);
        return result;
    }
};