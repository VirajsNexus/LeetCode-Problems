class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int result = x ^ y;     //XOR operation

        int count = 0;

        while(result > 0)
        {
            count += result & 1;    //check last bit
            result = result >> 1;   //perform right shift
        }    

        return count;
    }
};