class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        int i=0;
        while(i<s.length())
        {
            if(st.empty())
                st.push({s[i],1});
            else
            {
                if(st.top().first == s[i])
                    st.top().second++;
                else
                    st.push({s[i],1});
            }
            if(st.top().second == k)
                st.pop();
            i++;
        }
        string str="";
        while(!st.empty())
        {
            str = string(st.top().second, st.top().first) + str;
            st.pop();
        }
        return str;
    }
};