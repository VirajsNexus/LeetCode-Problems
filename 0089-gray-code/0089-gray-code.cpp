class Solution {
public:
    vector<int> grayCode(int n) 
    {
        //For any non-negative integer n (in binary form), its Gray code equivalent G(n) can be calculated using the
        // bitwise formula: Gray_Value = n < (n >> 1)

        //total number of Gray Codes will be 2^n equivalent to 1 << n
        int TotalCodes = 1 << n;

        //Consider a vector to store result
        vector <int> result;

        for(int i = 0; i < TotalCodes; i++)
        {
            //Hint : Use right shift and XOR opertor for differ results of each
            //formula : Gray(i) = i ^ (i >> 1)

            int GrayCode = i ^ (i >> 1);        //separate for each
            //Use push_back function to store in result vector
            result.push_back(GrayCode);
        }
        return result;
    }
};