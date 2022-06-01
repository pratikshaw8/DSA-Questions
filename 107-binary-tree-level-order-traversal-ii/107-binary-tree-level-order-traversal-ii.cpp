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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> line;
        int i=0,j=0;
        if(root==NULL)
            return ans;
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                ans.insert(ans.begin(),line);
                line.clear();
                
                
                if(!q.empty())
                    q.push(NULL);
                
            }
            else
            {
                line.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
        
    }
};








