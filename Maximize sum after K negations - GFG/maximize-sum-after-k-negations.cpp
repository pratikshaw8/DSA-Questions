// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        
        long long sum=0;
        for(int i=0;i<n;i++)
        {

            if(k>0 and a[i] < 0)
            {
                a[i]= - a[i];
                k--;
            }
            sum+=a[i];
        }
        
        if(k%2==1)
        {
            long long int mn=*min_element(a,a+n);
            sum-= 2*mn;
        }
        return sum;
        
        
        
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends