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
//     void inOrder(TreeNode* root, int &cnt){
//         if(!root) return;
        
//         cnt++; 
//         inOrder(root->left, cnt);
//         inOrder(root->right, cnt);
//     }
    int rightheight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
    int leftheight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        //Approach 2
        
        if(!root) return 0;
        
        int lh= leftheight(root);
        int rh= rightheight(root);
        
        if(lh==rh) return (1<<lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        //Approach 1 Inorder traversal
        // int cnt=0;
        // inOrder(root, cnt);
        // return cnt;
    }
};