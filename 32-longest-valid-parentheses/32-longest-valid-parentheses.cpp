class Solution {
public:
    
    
    int longestValidParentheses(string s) {
        
        int ans=0;
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(!st.empty() and s[st.top()]=='(')
                {
                    st.pop();
                    int x;
                    if(!st.empty())
                        x=st.top();
                    else 
                        x=-1;
                    ans=max(ans,i-x);
                }
                else
                    st.push(i);
                
            }
        }
        return ans;
    }
};