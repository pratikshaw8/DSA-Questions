// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int a=-1,b=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x and a==-1)
        a=i;
        if(arr[n-i-1] == x and b==-1)
        b=n-i-1;
    }
    
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends