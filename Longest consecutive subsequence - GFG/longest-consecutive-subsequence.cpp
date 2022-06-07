// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int> m;
      int maxi=INT_MIN;
      
      for(int i=0;i<N;i++)
      {
          maxi=max(maxi,arr[i]);
          m[arr[i]]++;
      }
      
      int c=0,ans=0;
      for(int i=1;i<=maxi;i++)
      {
          if(m[i])
          c++;
          else
          {
              ans=max(ans,c);
              c=0;
          }
      }
      ans=max(ans,c);
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends