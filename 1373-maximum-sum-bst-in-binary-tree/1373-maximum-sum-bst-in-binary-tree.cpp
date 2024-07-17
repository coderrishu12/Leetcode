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

class NodeValue{
    public:
    int minNode, maxNode, sum;
    NodeValue( int minNode,int maxNode,  int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        
        this->sum     = sum; 
    }
};
class Solution {
    int ans;
    private:
    NodeValue largestSubtree(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        
        auto left = largestSubtree(root->left);
        auto right = largestSubtree(root->right);
        
        if(left.maxNode < root->val && root->val < right.minNode  ){
            int s=  left.sum + right.sum+ root->val;
            ans = max(ans,s);
            return NodeValue(min(root->val, left.minNode) , max(root->val, right.maxNode),s);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.sum , right.sum));
        
    }
    
public:
    int maxSumBST(TreeNode* root) {
        ans=0;
        largestSubtree(root).sum;
        return ans;
    }
};