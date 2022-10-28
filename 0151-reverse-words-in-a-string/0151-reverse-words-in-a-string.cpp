class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        s+=" ";
        stack<string> st;
        int i=0;
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
                temp+=s[i];
            else
            {
                if(temp!="")
                    st.push(temp);
                temp="";
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans += st.top()+" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
}; 