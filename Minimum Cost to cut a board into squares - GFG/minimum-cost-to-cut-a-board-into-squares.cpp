// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        if(M <N)
        return minimumCostOfBreaking(Y,X,N,M);
        
        sort(Y.begin(),Y.end(),greater<int>());
        sort(X.begin(),X.end(),greater<int>());
        
        int ans=0;
        int c=0;
        int i=0,j=0;
        int hori=1,vert=1;
        while(c <M+N and i<M and j<N)
        {
            if( X[i] >=Y[j])
            {
                ans += X[i]*vert;
                hori++;
                i++;
            }
            else
            {
                ans+= Y[j]*hori;
                vert++;
                j++;
            }
            c++;
        }
        while(i<M)
        {
            ans += X[i]*vert;
            hori++;
            i++;
        }
        while(j<N)
        {
            ans += Y[j]*hori;
            vert++;
            j++;
        }
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends