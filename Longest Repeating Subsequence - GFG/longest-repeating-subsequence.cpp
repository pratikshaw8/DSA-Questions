// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int solve(string str,int i,int j, vector<vector<int>>& dp)
	    {
	        
	        if(i==0 or j==0) return 0;
	        
	        if(dp[i][j]!=-1) return dp[i][j];
	        
	        if(str[i-1]==str[j-1] and i!=j)
	        return dp[i][j]=1+solve(str,i-1,j-1,dp);
	        else
	        {
	            return dp[i][j]=max(solve(str,i-1,j,dp),solve(str,i,j-1,dp));
	        }
	        
	    }
	    int tabulation(string str)
	    {
	        int n=str.length();
	        vector<vector<int>> dp(n+1,vector<int>(n+1));
	        
	        for(int i=1;i<=n;i++)
	        {
	            
	            for(int j=1;j<=n;j++)
	            {
	                if(str[i-1]==str[j-1] and i!=j)
	                dp[i][j]=1+dp[i-1][j-1];
	                else
	                {
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	        return dp[n][n];
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here   
		    int n=str.length();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    return tabulation(str);
		   return solve(str,n,n,dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends