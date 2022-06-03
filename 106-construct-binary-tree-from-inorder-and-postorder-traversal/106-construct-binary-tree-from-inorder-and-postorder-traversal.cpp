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
    int i;
    unordered_map<int,int> m;
     
    TreeNode *solve(vector<int> post, int start, int end)
    {
        if( start > end)
        return NULL;

        int curr=post[i];
        TreeNode *node=new TreeNode(curr);
        int pos=m[curr];
        i--;
        
        if(start==end)
            return node;

        node->right=solve(post,pos+1,end);
        node->left=solve(post,start,pos-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int n=in.size();
        i=n-1;
        
        
        
        for(int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
    
        TreeNode *ans=solve(post,0,n-1);
        return ans;
    }
};