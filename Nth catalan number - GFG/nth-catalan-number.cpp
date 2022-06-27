// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    cpp_int solve(int n,vector<cpp_int>& dp)
    {
        if(n==0)
        return 1;
        if(n==1)
        return 1;
        
        if(dp[n]!=0) return dp[n];
        
        
        
        for(int i=0;i<=n;i++)
        {
            dp[n] += solve(i,dp) *solve(n-i-1,dp);
        }
        
        return dp[n];
    }
    cpp_int tabulation(int n)
    {
        vector<cpp_int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int> dp(n+1,0);
        return tabulation(n);
        return solve(n,dp);
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends