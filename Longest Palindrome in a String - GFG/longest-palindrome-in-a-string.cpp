// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.length();
        if(n<2)
        return s;
        
        int maxi=0,start=0;
        int low,high;
        for(int i=0;i<n;i++)
        {
            low=i-1;
            high=i+1;
            
            while(high < n and s[high]==s[i])
            high++;
            
            while(low>=0 and s[low]==s[i])
            low--;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                low--;
                high++;
            }
            if(maxi < high-low-1)
            {
                maxi=high-low-1;
                start=low+1;
            }
        }
        return s.substr(start,maxi);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends