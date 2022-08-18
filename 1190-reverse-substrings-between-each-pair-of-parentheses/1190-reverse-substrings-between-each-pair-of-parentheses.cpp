class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string temp="";

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')')
            {
                while(!st.empty() and st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                if(!st.empty())
                st.pop();
                for(auto c:temp)
                    st.push(c);
                temp="";
            }
            else
                st.push(s[i]);
        }
        temp="";
        while(!st.empty() )
        {
            temp=st.top() +temp;
            st.pop();
        }
        
        return temp;
    }
};