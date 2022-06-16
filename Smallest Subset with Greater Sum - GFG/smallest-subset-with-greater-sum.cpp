// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int n){
        
        sort(Arr.begin(),Arr.end());
        
        long long totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum+=Arr[i];
        }
        
        if(totalSum == 0) return n;
        
        long long minSum=0;
        int i;
        for(i=n-1;i>=0;i--)
        {
            minSum+=Arr[i];
            totalSum-=Arr[i];
            if(minSum> totalSum)
            return n-i;
        }
        
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends