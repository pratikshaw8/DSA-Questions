/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* target, int k, vector<int>& ans, 
     unordered_map<TreeNode*,TreeNode*>& parent, unordered_map<TreeNode*,bool> &visited) 
    {
        if(target==NULL)return;
        
        if(k==0)
        {
            ans.push_back(target->val);
            return;
        }
        visited[target] = true;
        
        if(visited.find(target->left) == visited.end() or !visited[target->left])
        solve(target->left, k-1,ans,parent,visited);
        if(visited.find(target->right) == visited.end() or !visited[target->right])
        solve(target->right,k-1,ans,parent,visited);
        
        TreeNode* par = parent[target];
        
        if(visited.find(par) == visited.end() or !visited[par])        
        solve(par,k-1,ans,parent,visited);
        
        
    }
    void findParent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            parent[root->left]=root;
            findParent(root->left,parent);
        }
        if(root->right)
        {
            parent[root->right]=root;
            findParent(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=NULL;
        
        //store all parents
        findParent(root,parent);
        
        unordered_map<TreeNode*,bool> visited;
        solve(target,k,ans,parent,visited);
        return ans;
    }
};
