// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        if(n==1)
        return "";
        unordered_map<string,int> m;
        int mx=0;
        string s="";
        for(int i=0 ; i<n ;i++)
        {
            m[arr[i]]++;
            if(mx < m[arr[i]])
            {
                s=arr[i];
                mx=m[arr[i]];
            }
        }
        m.erase(s);
        mx=0;
        s="";
        for (auto it:m)
        {
            if(mx < it.second)
            {
                s=it.first;
                mx=it.second;
            }
        }
        return s;
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends