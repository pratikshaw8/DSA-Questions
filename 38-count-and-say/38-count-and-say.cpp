#include<string>
class Solution {
public:
    
    
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        
        string say=countAndSay(n-1);
        
        string ans;
        int size=say.length();
        char tmp=say[0];
        if(size==1)
            return "11";
        
        int i=0;
        int c=0;
        while(i<size)
        {
            char ch=say[i];
            if(tmp==ch)
            {
                c++;
                
            }
            else
            {
                string temp;
                temp.push_back(tmp);
                ans+= to_string(c) +temp;
                tmp=say[i];
                c=1;
                
            }
            i++;
                
        }
        string temp;
        temp.push_back(tmp);
        ans+= to_string(c)+temp;
        return ans;
        
    }
};