// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char a)
    {
        if(a=='/' || a=='*')
        return 2;
        else if(a=='^')
        return 3;
        else if(a=='+' or a=='-')
        return 1;
        else
        return 0;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        
        s= s +')';
        
        
        stack<char> st;
        st.push('(');
        
        string ans;
        for(int i=0;i<s.length();i++)
        {
            char a=s[i];
            
            switch(a)
            {
                case '(': st.push(a);
                break;
                
                case ')': while(!st.empty() and st.top()!='(')
                          {
                              ans.push_back(st.top());
                              st.pop();
                          }
                          st.pop();
                break;
                
                case '+':
                case '/':
                case '*':
                case '-':
                case '^': if(st.empty() or st.top()== '(')
                            st.push(a);
                          else
                          {
                              while(!st.empty() and prec(st.top()) >= prec(a))
                              {
                                  ans.push_back(st.top());
                                  st.pop();
                              }
                              
                              st.push(a);
                          }
                break;
                
                default: ans.push_back(a);
            }
            
            
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            
        }
        
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends