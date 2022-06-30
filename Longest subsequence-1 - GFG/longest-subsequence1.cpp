// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int tabulation(int n, int a[])
    {
        unordered_map<int,int >m;

        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int l=0;
            if(m[a[i]-1]) l=m[a[i]-1];
            if(m[a[i]+1 ] and m[a[i]+1] >l) l=m[a[i]+1];
            
            m[a[i]]=l+1;
            ans=max(ans,l+1);
            
        }
        return ans;
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        return tabulation(N,A);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends