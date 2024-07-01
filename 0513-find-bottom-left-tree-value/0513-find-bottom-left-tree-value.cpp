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
//     int bottomLeft;
//     void DFS(TreeNode* root, int currDepth){
//         if(!root) return ;
        
//         if(currDepth>maxDepth){
//             maxDepth=currDepth;
//             bottomLeft=root->val;
//         }
//         DFS(root->left, currDepth+1);
//         DFS(root->right, currDepth+1);

//     }
    int findBottomLeftValue(TreeNode* root) {
//         Approach 3 Level by Level
          queue<TreeNode*> q;
        q.push(root);
        int maxi=-1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* root = q.front();
                q.pop();
                maxi=root->val;
                
            
            
            if(root->right){
                q.push(root->right);
            }
            if(root->left){
                q.push(root->left);
            }
            }
        }
        return maxi;
        
//         Approach 2 BFS
        
//         queue<TreeNode*> q;
//         q.push(root);
//         int maxi=-1;
//         while(!q.empty()){
//             TreeNode* root = q.front();
//             q.pop();
//             maxi=root->val;
            
//             if(root->right){
//                 q.push(root->right);
//             }
//             if(root->left){
//                 q.push(root->left);
//             }
//         }
        // return maxi;
        
        
//         Approach 1 DFS
        
        // maxDepth=-1;
        // DFS(root, 0);
        // return bottomLeft;
    }
};