class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.push_back(asteroids[0]);
        int i=1;
        
        while(i<asteroids.size())
        {
            if(ans.empty() or asteroids[i] > 0){
                ans.push_back(asteroids[i]);
                i++;
            }
            else
            {
                if(ans.back() < 0){
                    ans.push_back(asteroids[i]);
                    i++;
                }
                else if(ans.back() > abs(asteroids[i]))
                    i++;
                else if(ans.back() < abs(asteroids[i]))
                {
                    ans.pop_back();
                }
                else{
                    ans.pop_back();
                    i++;
                }
            }
        }
        
        
        return ans;
    }
};