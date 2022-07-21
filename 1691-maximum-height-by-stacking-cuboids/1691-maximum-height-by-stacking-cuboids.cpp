class Solution {
public:
    bool check(vector<int> &a, vector<int> &b)
    {
        if(a[0] >= b[0] and a[1] >= b[1] and a[2] >= b[2])
            return true;
        else
            return false;
    }
    int LIS(int n, vector<vector<int>>& a)
    {
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int curr=n-1; curr>=0 ;curr--)
        {
            for(int prev = curr-1 ; prev>=-1 ;prev--)
            {
                int take=0;
                if(prev ==-1 or check(a[curr],a[prev]))
                {
                    take= a[curr][2] + nextRow[curr+1];
                }
                
                int notTake = nextRow[prev+1];
                
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        
        //sort each row
        for(int i=0;i<cuboids.size() ;i++){
            sort(cuboids[i].begin() , cuboids[i].end() );
        }
        
        //sort based on w
        sort(cuboids.begin(),cuboids.end() );
        return LIS(n,cuboids);
        
    }
};