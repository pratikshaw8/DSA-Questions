class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        
        if(jug1+jug2 < target)
            return false;
        else if(target==jug1 or target==jug2 or target==jug1+jug2)
            return true;
        
        
        return target % (__gcd(jug1,jug2))==0;
    }
};