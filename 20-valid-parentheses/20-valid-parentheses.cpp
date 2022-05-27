class Solution {
public:
    bool isValid(string s) {
        // Write your code here.
    stack<char> st;
    if(s.length() %2 ==1)
        return false;
    
    for(int i=0;i<s.length();i++)
    {
        switch(s[i])
        {
            case '(':
            case '{':
            case '[': st.push(s[i]);
                break;
                
            case ']':
                if(st.empty() or st.top()!= '[' )
                        return false;
                st.pop();
                break;
            case '}':
                if(st.empty() or st.top()!= '{' )
                        return false;
                st.pop();
                break;
            case ')':
                if(st.empty() or st.top()!= '(' )
                        return false;
                st.pop();
                break;
        }
        
    }
    if(st.empty())
        return true;
    else
        return false;
    }
};