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
     int height(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int lhSum =max(0, height(root->left, maxi)); //Sum from left
        int rhSum = max(0,height(root->right, maxi));//Sum from right
        
        maxi   = max(maxi,lhSum+rhSum + root->val); //store maximum sum
        
        return (root->val)+max(lhSum,rhSum);
    }
    int maxPathSum(TreeNode* root) {
       int dia=INT_MIN;
        height(root, dia);
        return dia;
    }
};
