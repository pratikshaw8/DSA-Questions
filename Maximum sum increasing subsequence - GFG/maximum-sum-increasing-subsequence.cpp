// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int tabulation(int a[],int n)
	{
	    vector<int> dp(a,a+n);
	    int ans=a[0];
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[j] <a[i])
	            {
	                dp[i]=max(dp[i],dp[j]+a[i]);
	                ans=max(ans,dp[i]);
	            }
	        }
	    }
	    return ans;
	    
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    return tabulation(arr,n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends