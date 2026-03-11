class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n == 0)
        {
            return 1;
        }

        int ans = 0;
        int power = 1;

        while(n > 0)
        {
            int bit = n % 2;        //last bit

            if(bit == 0)
            {
                ans = ans + power;  //flip bit
            }

            n = n / 2;              //next bits
            power = power * 2;      //increase binary value
        }

        return ans;
    }
};