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
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL) return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    TreeNode* solve( int i,int j, vector<int> ans)
    {

        if(i>j) return NULL;

        int mid= (i+j+1)/2;

        TreeNode* root=new TreeNode(ans[mid]);


        root->left=solve(i,mid-1,ans);
        root->right=solve(mid+1,j,ans);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        int i=0,j=ans.size()-1;


        return solve(i,j,ans);
    }
};