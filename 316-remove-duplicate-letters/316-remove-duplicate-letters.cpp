class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0);
        stack<char> st;
        
        for(char &ch:s)
            cnt[ch-'a']++;
        vector<bool> visi(26,false);
        
        string res="";
        for(char &ch:s)
        {
            cnt[ch-'a']--;
            if(visi[ch-'a'])  continue;
            
            while(res.size() > 0 and ch < res.back() and cnt[res.back()-'a'])
            {
                visi[res.back()-'a']=false;
                res.pop_back();
            }
            res+=ch;
            visi[ch-'a']=true;
        }
        return res;
    }
};