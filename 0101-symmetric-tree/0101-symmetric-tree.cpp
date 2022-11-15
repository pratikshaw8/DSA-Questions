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
    bool check(TreeNode *a, TreeNode *b)
    {
        if(a==NULL and b==NULL) return true;
        if(a==NULL or b == NULL) return false;
        
        return a->val == b->val and check(a->left,b->right) and check(a->right, b->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root or (!root->left and !root->right)) return true;
        return check(root->left,root->right);
    }
};