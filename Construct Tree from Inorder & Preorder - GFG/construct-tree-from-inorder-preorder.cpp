// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int idx=0;
    map<int,int> m;
    void createMap(int in[] ,int n)
    {
        for(int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
        
    }
    
    Node * solve(int in[],int pre[],int start,int end)
    {
        
        if(start>end)
        return NULL;
        
       
        int curr=pre[idx];
        int pos=m[curr];
        idx++;
        
        Node *newNode= new Node(curr);
        
        if(start==end)
        return newNode;
        
        newNode->left= solve(in,pre,start,pos-1);
        newNode->right= solve(in,pre,pos+1,end);
        
        return newNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        createMap(in,n);
        Node * ans=solve(in,pre,0,n-1);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends