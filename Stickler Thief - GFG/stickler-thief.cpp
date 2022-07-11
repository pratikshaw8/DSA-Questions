// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    int solve(int arr[],int n ,int i,vector<int>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1) return dp[i];
        int inc,exc;
        
        exc=solve(arr,n,i+1,dp);
        inc= arr[i] +solve(arr,n,i+2,dp);
        return dp[i]=max(exc,inc);
    }
    int tabulation(int arr[],int n)
    {
        
        int prev2=0;
        int prev1=arr[0];
        for(int i=1;i<n;i++)
        {
            int ans =max(prev1, prev2 + arr[i]);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
        
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return tabulation(arr,n);
        vector<int> dp(n+1,-1);
        return solve(arr,n,0,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends