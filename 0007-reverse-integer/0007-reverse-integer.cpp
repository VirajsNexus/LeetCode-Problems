class Solution {
public:
    int reverse(int x) 
    {
        //Note : environment does not store 64 bit integers

        int revInt = 0;

        while(x != 0)
        {
            int digit = x % 10;     //gets last digit
            x = x / 10;             //Last digit removed

            //Overflow Checking with respect to 32 bit integer
            if(revInt > INT_MAX /10 || revInt < INT_MIN / 10)
            {
                return 0;
            }

            revInt = revInt * 10 + digit;       //actual reverse happens here
        }    

        return revInt;
    }
};