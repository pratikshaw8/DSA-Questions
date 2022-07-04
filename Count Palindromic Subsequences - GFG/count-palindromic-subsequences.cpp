// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        long m=1e9+7;
       //Your code here
       int n=str.length();
       long long int dp[n][n];
       
       for(int i=n-1;i>=0;i--)
       {
           for(int j=0;j<n;j++)
           {
               if(i>j)
               dp[i][j]=0;
               else if(i==j)
               dp[i][j]=1;
               else
               {
                   if(str[i] == str[j])
                   {
                       dp[i][j]= ( dp[i+1][j] + dp[i][j-1] +1) %m;
                   }
                   else
                   {
                       dp[i][j]= (dp[i+1][j] + dp[i][j-1] -dp[i+1][j-1] +m)%m;
                   }
               }
           }
       }
       return dp[0][n-1];
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends