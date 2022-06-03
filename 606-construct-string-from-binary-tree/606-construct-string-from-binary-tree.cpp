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
    void solve(TreeNode *root,string& ans)
    {
        if(root==NULL)
        {
            
            return;
        }
        
        string a=to_string(root->val);
        if(root->right ==NULL and root->left ==NULL)
        {
            ans+=a;
            ans.push_back(')');
            return;
        }
        
        
        ans+=a;
        
        if(root->left==NULL and root->right!=NULL)
            ans+="()";
        else
        {
            ans+='(';
            solve(root->left,ans);
        }
        
        if(root->right)
        {
            ans+='(';
              
        }
        solve(root->right,ans);
        ans.push_back(')');
        
        
    }
    string tree2str(TreeNode* root) {
        
        
        string ans;
        if(root==NULL)
            return ans;
        solve(root,ans);
        ans.pop_back();
        return ans;
    }
};