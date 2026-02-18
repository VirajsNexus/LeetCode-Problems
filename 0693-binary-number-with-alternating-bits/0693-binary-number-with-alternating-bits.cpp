class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
         int prev = n % 2;   // last bit
        n = n / 2;
        
        while(n > 0)
        {
            int curr = n % 2;   // current bit
            
            if(curr == prev)   // if same as previous
                return false;
            
            prev = curr;       // update previous
            n = n / 2;         // move to next bit
        }
        
        return true;
    }
};