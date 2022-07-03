// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int low=0,high=0;
        int n=a.size();
        int ans=0;
        while(high<n)
        {
            if(a[high]-a[low]<=k)
            {
                ans =max(ans,high-low+1);
                high++;
            }
            else
            {
                low++;
            }
        }
        return n-ans;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends