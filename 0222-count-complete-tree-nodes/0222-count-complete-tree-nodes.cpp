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
    int countLastLevel(TreeNode *root, int height)
    {
        if(height == 1)
        {
            if(root->right!= NULL) return 2;
            else if(root->left != NULL) return 1;
            else
                return 0;
        }
        
        TreeNode *curr = root->left;
        int currHeight=1;
        
        while(currHeight < height)
        {
            currHeight++;
            curr = curr ->right;
        }
        
        if(curr==NULL) return countLastLevel(root->left,height-1);
        return (1<<(height-1)) + countLastLevel(root->right, height-1);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left ==NULL) return 1;
        int height=0;
        int nodesSum = 0;
        TreeNode *curr = root;
        
        while(curr->left)
        {
            nodesSum += (1<<height);
            height++;
            curr= curr->left;
        }
               
        return nodesSum + countLastLevel(root, height);
    }
};