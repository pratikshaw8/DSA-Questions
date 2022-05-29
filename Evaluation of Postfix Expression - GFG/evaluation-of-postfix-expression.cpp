// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    int operation(int x,int y, char op)
    {
    if(op=='/')
        return x/y;
    else if(op=='*')
        return x*y;
    else if(op=='+')
       return x+y;
    else
        return x-y;
    }
    
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        int ans=0,x,y;
    
    stack<int> st;
    
    for(int i=0;i<S.length();i++)
    {
        char a=S[i];
        
        switch(a)
        {                
            case '+':
            case '*':
            case '/':
            case '-': 
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                
                ans= operation(y,x,a);
                
                st.push(ans);
                
                break;
                
            default: 
                int num=(int)(a-'0');
                st.push(num);
        }
        
        
    }
    if(!st.empty())
    return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends