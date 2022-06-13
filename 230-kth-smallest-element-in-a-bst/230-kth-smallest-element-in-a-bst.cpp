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
    int i=1;
    int kthSmallest(TreeNode* root, int k) {
        
        if(root==NULL) return -1;
        
        int l=kthSmallest(root->left,k);
        
        if(l!=-1)
            return l;
        
        if(k==i) return root->val;
        i++;
        
        return kthSmallest(root->right,k);
    }
};