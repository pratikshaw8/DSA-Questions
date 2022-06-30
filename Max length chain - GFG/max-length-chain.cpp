// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
static bool mycmp(val a, val b)
{
    return a.first< b.first;
}
int solve(struct val p[], int n,int i,struct val a,vector<int>& dp)
{
    if(i==n)
    return 0;
    if(dp[i]!=-1) return dp[i];
    
    if(a.second < p[i].first )
    {
        return dp[i]=max(1+solve(p,n,i+1,p[i],dp),solve(p,n,i+1,a,dp));
    }
    else
    return dp[i]=solve(p,n,i+1,a,dp);
}
int tabulation(struct val p[],int n)
{
    sort(p,p+n,mycmp);
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[j].second < p[i].first)
            dp[i]=max(dp[i],1+dp[j]);
        }
    }
    return *max_element(dp.begin(),dp.end());
    
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    //Your code here
    return tabulation(p,n);
    vector<int> dp(n+1,-1);
    struct val a;
    a.first=0;
    a.second=0;
    return solve(p,n,0,a,dp);
}