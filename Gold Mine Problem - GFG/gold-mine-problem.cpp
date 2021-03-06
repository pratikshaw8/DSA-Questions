// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int x,int y,int n,int m)
    {
        if(x<0 or y<0 or x>=n or y>=m)
        return false;
        return true;
    }
    int solve(int x, int y, int n,int m, vector<vector<int>>& M ,vector<vector<int>> &dp)
    {
        if(!isSafe(x,y,n,m))
        return 0;
        
        if(dp[x][y]!=-1)
        return dp[x][y];
        
        int ur=M[x][y]+solve(x-1,y+1,n,m,M,dp);
        int r=M[x][y]+solve(x,y+1,n,m,M,dp);
        int dr=M[x][y]+solve(x+1,y+1,n,m,M,dp);
        
        return dp[x][y]=max(ur,max(r,dr));
    }
    int tabulation(int n,int m,vector<vector<int>> M)
    {
      
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,M[i][0]);
            
        int x;
            
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                x=M[j][i-1];
                if(j-1>=0)
                    x=max(x,M[j-1][i-1]);
                if(j+1<n)
                    x=max(x,M[j+1][i-1]);
                    
                M[j][i]+=x;
                ans=max(ans,M[j][i]);
            }
        }
        
        return ans;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        // int maxi=INT_MIN;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        
        // for(int i=0;i<n;i++)
        // {
        //     maxi=max(maxi, solve(i,0,n,m,M,dp));
        // }
        // return maxi;
        
        return tabulation(n,m,M);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends