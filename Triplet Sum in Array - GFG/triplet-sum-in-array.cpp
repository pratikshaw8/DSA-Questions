// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        int s=0,e=n-1;
        
        for(int i=0;i<n;i++)
        {
            int target=X-A[i];
            if(target < 0)
            continue;
            
            s=0;
            e=n-1;
            while(s < e)
            {
                if(s==i)
                s++;
                else if(e==i)
                e--;
                
                if(A[s] +A[e] ==target)
                return true;
                else if(A[s] +A[e] <target)
                s++;
                else
                e--;
                
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends