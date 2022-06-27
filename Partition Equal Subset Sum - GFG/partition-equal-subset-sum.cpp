// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N, int arr[],int sum,vector<vector<int>>& dp)
    {
        if(sum==0) return 1;
        if(N==0) return 0;
        
        if(dp[N][sum]!=-1) return dp[N][sum];
        
        if(arr[N-1] > sum)
        return dp[N][sum]=solve(N-1,arr,sum,dp) ;
        
        return dp[N][sum]=solve(N-1,arr,sum-arr[N-1],dp) or solve(N-1, arr ,sum,dp);
        
    }
    int tabulation(int n, int arr[],int sum)
    {
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0;i<=sum;i++)
            dp[0][i]=0;
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
       
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] or dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum %2 ==1) return 0;
        sum=sum/2;
        
        vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));
        return tabulation(N,arr,sum);
        return solve(N,arr,sum,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends