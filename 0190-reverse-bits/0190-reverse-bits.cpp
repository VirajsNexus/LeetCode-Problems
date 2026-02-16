class Solution {
public:
    int reverseBits(int n) 
    {
        unsigned int result = 0;

        for(int i =0; i <32; i++)
        {
            //shift result left to make hole at end
            result = result << 1;

            //If the last bit of n is 1 then put a 1 in that hole
            if(n & 1)
            {
                result++;
            }

            //Throw last bit of n so we can see the next one 
            n = n >> 1;
        }    

        return result;
    }
};