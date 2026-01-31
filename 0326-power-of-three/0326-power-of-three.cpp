class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        //Logic: If a number is a power of 3, dividing it by 3 again and again will finally give 1.
        //keep dividing it by 3 until it becomes small, cause power of 3 are always 0 or 3 or greater than 3
        //but at first the edge case is power of 3 numers are always positive
        if(n <= 0)
            return false;
        while(n >= 3)
        {
            //if n is not divisible by 3, then it can not be power of 3
            if(n % 3 != 0)
                return false;       //Describes n id not power of three

            //Now n can be power of three, Divide n by 3 and keep checking
            n= n/3;
        }
        //After this loop n can be 1, 2 or 3
        //Hence, n ==1 is the only valid power of three; as 3^0 = 1
        return n ==1;
    }
};