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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
       
        if(root==NULL) return NULL;
        
        if(root->val == p || root->val == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
    
    bool findPath(TreeNode* LCA, int target, string& path){
        if(LCA == NULL){
            return false;
        }
        
        if(LCA->val == target){
            return true;
        }
        
        path.push_back('L');
        if(findPath(LCA->left, target, path)==true){
            return true;
        }
        
        path.pop_back();
        
        path.push_back('R');
        if(findPath(LCA->right, target, path)==true){
            return true;
        }
        
        path.pop_back();
        return false;
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);
        
        string lcaTOSrc = "";
        string lcaTODest= "";
        
        findPath(LCA, startValue, lcaTOSrc);
        findPath(LCA, destValue, lcaTODest);
        
        string result = "";
        for(int i=0;i<lcaTOSrc.length();i++){
            result.push_back('U');
        }
        
        result+=lcaTODest;
        return result;
    }
};