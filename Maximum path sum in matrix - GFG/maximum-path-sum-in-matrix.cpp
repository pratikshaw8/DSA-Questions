// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n, vector<vector<int>> &m, int row, int col,vector<vector<int>> &dp)
    {
        if(col<0 or col>=n or row>=n or row<0)
        return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int a=solve(n,m,row+1,col,dp);
        int b=solve(n,m,row+1,col-1,dp);
        int c=solve(n,m,row+1,col+1,dp);
        
        return dp[row][col]=max(a,max(b,c)) +m[row][col];
        
    }
    int tabulation(int n, vector<vector<int>>& m)
    {
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
            dp[0][i] = m[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int maxi=0;
                if(i-1>=0) maxi=max(maxi,dp[i-1][j]);
                
                if(i-1>=0 and j-1>=0) maxi=max(maxi,dp[i-1][j-1]);
                
                if(i-1>=0 and j+1<n) maxi=max(maxi,dp[i-1][j+1]);
                
                dp[i][j]=maxi+m[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        return tabulation(N,Matrix);
        int result=0;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++)
        {
            result=max(result,solve(N,Matrix,0,i,dp));
        }
        return result;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends