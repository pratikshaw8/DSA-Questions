class Solution {
public:
    
    string removeDuplicates(string s) {
       stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() or st.top()!=s[i])
                st.push(s[i]);
            else
                st.pop();            
        }
        string r="";
        while(!st.empty())
        {
            r += st.top();
            st.pop();
        }
        reverse(r.begin(),r.end());
        return r;
    }
};