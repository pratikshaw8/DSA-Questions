class Solution {
public:
    static bool comp(pair<string, char> a, pair<string, char> b)
    {
        if(a.first==b.first)
            return a.second < b.second;
        
        return a.first < b.first;
    }
    
    string rankTeams(vector<string>& votes) {
        vector<pair<string,char>> vec(26,{"",'a'});
        
        for(auto vote:votes)
        {
            for(int i=0; i<vote.size() ;i++)
            {
                vec[vote[i]-'A'].first += (i+'0');
                vec[vote[i] -'A'].second = vote[i];
            }
        }
        
        for(int i=0; i<26; i++)
            sort(vec[i].first.begin(), vec[i].first.end());
        
        sort(vec.begin(), vec.end(), comp);
        
        string ans="";
        for(auto itr: vec)
        {
            if(itr.first!="")
                ans+=itr.second;
        }
        
        return ans;
    }
};