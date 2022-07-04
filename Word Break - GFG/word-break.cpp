// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(string &a,vector<string> &b )
    {
        unordered_map<string,int> dp;
        int n=a.length();
        if(n==0)
        return 1;
        
        if(dp[a]!=0)
        return dp[a];
        
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            string s=a.substr(0,i);
            
            for(int j=0;j<b.size();j++)
            {
                if(s.compare(b[j]) == 0)
                {
                    flag=1;
                    break;
                }
            }
            string temp=a.substr(i, n-i);
            if(flag==1 and solve(temp, b) == 1 )
            return dp[a]=1;
        }
        return dp[a]=-1;
       
        
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int ans=solve(A,B);
        if(ans==1)
        return 1;
        else
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends