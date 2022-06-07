// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> res={1};
        
        for(int i=2;i<=N;i++)
        {
            long long carry=0;
            int len=res.size()-1;
            
            while(len >=0)
            {
                long long temp= res[len]* i +carry;
                res[len]=temp%10;
                carry=temp/10;
                len--;
            }
            while(carry>0)
            {
                res.insert(res.begin(),carry%10);
                carry/=10;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends