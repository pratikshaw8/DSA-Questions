// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    long long int findMaxProduct(vector<int>&arr, int n){
        //Write your code here  
        
        if(arr.size()==1)
        return arr[0];
	    long long ans=1;
	    int mini=INT_MIN;
	    int maxi=INT_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,arr[i]);
	        if(arr[i]==0) continue;
	        
	        ans= (ans*arr[i])%mod;
	        
	        if(arr[i] <0 )
	        mini=max(mini,arr[i]);
	    }
	    if(maxi==0 and arr.size()==2)
	    return 0;
	    
	    if(ans <0)
	    ans=ans/mini;
	    return ans;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends