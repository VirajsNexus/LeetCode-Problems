class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int xor1 = 0;
        int xor2 = 0;

        int size1 = arr1.size();
        int size2 = arr2.size();

        for(int i = 0; i < size1; i++)
        {
            xor1 ^= arr1[i];
        }

        for(int i = 0; i< size2; i++)
        {
            xor2 ^= arr2[i];
        }

        return xor1 & xor2;
    }
};