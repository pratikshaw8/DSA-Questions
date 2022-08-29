class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
            
        vector<int> left(n);
        vector<int> right(n);
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,height[i]);
            left[i]=maxi;
        }
        maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,height[i]);
            right[i]=maxi;
        }
        
        int rain=0;
        for(int i=0;i<n;i++)
        {
            if(right[i] > height[i])
            {
                int mini = min(right[i],left[i]);
                
                rain += (mini-height[i]);
            }
        }
        return rain;
    }
    
};