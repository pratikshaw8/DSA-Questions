class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        queue<char> q;
        unordered_map<char,bool> mp;
        int maxi=1;
        mp[s[0]]=true;
        q.push(s[0]);
        
        for(int i=1;i<s.length();i++)
        {
            if(mp.find(s[i]) != mp.end() )
            {
                int size=q.size();
                maxi=max(maxi,size);
                int j=i-size;
                do
                {
                    char front=q.front();
                    q.pop();
                    mp.erase(front);
                    if(front == s[i])
                        break;
                    j++;
                }while(j<i and !q.empty());
                
            }
            mp[s[i]]=true;
            q.push(s[i]);
        }
        int size=q.size();
        maxi=max(maxi,size);
        
        return maxi;
            
    }
};