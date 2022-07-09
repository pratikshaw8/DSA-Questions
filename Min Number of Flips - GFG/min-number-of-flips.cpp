// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int c1=0,c2=0;
    
    
    for(int i=0 ; i<S.length() ; i++)
    {
        if(i%2==0)
        {
            c1 += S[i]=='1';
            c2 += S[i]=='0';
        }
        else
        {
            c1 += S[i]=='0';
            c2 += S[i]=='1';
        }
    }
    return min(c1,c2);
}