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
    
    int min_val(TreeNode *root)
    {
        if(root->left==NULL)
        return root->val;

        return min_val(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return root;
        
        if(root->val ==key)
        {
            //0 child
            if(!root->left and !root->right)
            {
                delete root;
                return NULL;
            }
            else if(!root->left) //only right child
            {
                TreeNode *t=root->right;
                delete root;
                return t;
            }
            else if(!root->right) //only left child
            {
                TreeNode *t=root->left;
                delete root;
                return t;
            }
            else
            {
                int mini=min_val(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val >key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        
    }
};