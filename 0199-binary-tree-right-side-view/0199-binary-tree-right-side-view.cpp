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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        map<int, int> mp;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int x=it.second;
             if (mp.find(x) == mp.end()) {
                mp[x] = node->val;
             }
            
            if(node->right){
                q.push({node->right, x+1});
            }
            if(node->left){
                q.push({node->left, x + 1});
            }
        }        
        
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};