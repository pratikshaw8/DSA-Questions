// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int count=0;
    for(int gap=0;gap<n;gap++)
    {
        for(int st=0,e=gap ; e<n ; st++,e++)
        {
            if(gap==0)
            dp[st][e]=true;
            else if(gap==1)
            {
                dp[st][e]= s[st]==s[e];
                if(dp[st][e]) count++;
            }
            else
            {
                dp[st][e] =( s[st] == s[e] and dp[st+1][e-1]);
                if(dp[st][e]) count++;
            }
            
        }
    }
    return count;
    
}