// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.size() &1)
    return -1;
    
    int open=0;
    int close=0;
    stack<char>st;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{')
        {
            st.push('{');
            open++;
        }
        else
        {
            if(!st.empty() and st.top()=='{')
            {
                st.pop();
                open--;
            }
            else
            {
                st.push('}');
                close++;
            }
        }
    }
    
    
    return ((open+1)/2) +((close+1)/2);
    
    
}





