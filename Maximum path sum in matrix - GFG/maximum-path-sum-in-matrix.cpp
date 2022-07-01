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
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
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