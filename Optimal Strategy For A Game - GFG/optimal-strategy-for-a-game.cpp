// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[] ,int s, int e, vector<vector<int>>& dp)
    {
        if(s>=e)
        return 0;
        if(e-s==1)
        return max(arr[s],arr[e]);
        if(dp[s][e]!=-1) return dp[s][e];
        
        if((e-s+1)%2 ==0)
        {
            return dp[s][e]=max(arr[s] +solve(arr,s+1,e,dp), arr[e] +solve(arr,s,e-1,dp));
        }
        else
        {
            return dp[s][e]= min(solve(arr,s+1,e,dp),solve(arr,s,e-1,dp));
        }
    }
    long long tabulation()
    {
        
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(arr,0,n-1,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends