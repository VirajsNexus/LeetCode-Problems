class Solution {
public:
     //compares two numbers 'a' and 'b', and decide sorting order
    static bool check(int a, int b) 
    {
        // "__builtin_popcount" is a GCC compiler inbuilt function that efficiently counts the number of set bits (1s) in the binary representation of a number using hardware-level optimizations.
        // Count how many 1's (set bits) are present in 'a'
        int setBit1  = __builtin_popcount(a);

        // Count how many 1's (set bits) are present in 'b'
        int setBit2 = __builtin_popcount(b);

        // If both numbers have same number of set bits
        if(setBit1 == setBit2)
        {
            // Then sort them normally in ascending order
            return a < b;
        }   

        // Otherwise, the number with fewer set bits comes first
        return setBit1 < setBit2;
    }

    vector<int> sortByBits(vector<int>& arr)
    {
        // Sort the array using our custom comparison function 'check'
        sort(arr.begin(), arr.end(), check);

        // Return the sorted array
        return arr;

    }
};