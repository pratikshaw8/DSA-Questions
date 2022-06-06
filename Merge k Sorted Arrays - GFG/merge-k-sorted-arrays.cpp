// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
struct Element
{
    public :
    int value;
    int row;
    int col;
    Element(int v,int r,int c)
    {
        value=v;
        row=r;
        col=c;
        
    }
};
struct Comparator
{
    bool operator()(Element &e1,Element &e2)
    {
        return e1.value> e2.value;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<Element,vector<Element>,Comparator> minheap;
        
        for(int i=0;i<K;i++)
        {
            minheap.push(Element(arr[i][0],i,0));
        }
        
        while(!minheap.empty())
        {
            Element temp=minheap.top();
            int val=temp.value;
            int row=temp.row;
            int col=temp.col;
            
            ans.push_back(val);
            
            minheap.pop();
            
            if(col+1 <K)
            {
                minheap.push(Element(arr[row][col+1],row,col+1));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends