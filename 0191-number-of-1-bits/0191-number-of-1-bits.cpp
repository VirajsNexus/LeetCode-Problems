class Solution {
public:
    int hammingWeight(int n) 
    {
        int count = 0;

        while(n > 0)
        {
            if(n % 2 == 1)  
            {
                count++;    //if 1 increase count by 1
            }
            n = n/2;    //next bit
        }

        return count;
    }
};