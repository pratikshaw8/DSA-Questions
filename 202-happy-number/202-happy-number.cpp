class Solution {
public:
    int getNext(int n)
    {
        int sum=0;
            
        while(n)
        {
            int i=n%10;
            sum += i*i;
            n= n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=getNext(n);
        
        while(fast!=1 and slow!=fast)
        {
            slow=getNext(slow);
            fast=getNext(getNext(fast));
            
        }
        
        return fast == 1;
        
    }
};