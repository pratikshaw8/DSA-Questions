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
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;
    
    string solve(TreeNode* root)
    {
        if(root==NULL)
            return "";
        
        string ll = 'l'+solve(root->left);
        string rr = 'r' +solve (root->right);
        string g = ll + to_string(root->val) + rr;
        
        if(mp[g] == 1)
        {
            ans.push_back(root);
            mp[g]++;
        }
        mp[g]++;
        return g;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};