// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> m(256,0);
        
        int ans=INT_MAX;
        int start=0,count=0;
        
        for(int i=0;i<p.length() ;i++)
        {
            if(m[p[i]] == 0)
            count++;
            m[p[i]]++;
        }
        
        int i=0 ,j=0;
        
        while( j< s.length())
        {
            m[s[j]] -- ;
            if(m[s[j]] ==0)
            count--;
            
            if(count ==0 )
            {
                while(count==0)
                {
                    if(ans > j-i+1)
                    {
                        start=i;
                        ans=j-i+1;
                    }
                    m[s[i] ]++;
                    if(m[s[i]] >0)
                    count++;
                    i++;
                }
                
                
            }
            j++;
        }
        if(ans==INT_MAX)
        return "-1";
        else
        return s.substr(start,ans);
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends