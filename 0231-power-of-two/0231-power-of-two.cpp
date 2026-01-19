class Solution {
public:
    // Logic :-
    //  Powers of two (1, 2, 4, 8, 16, ...) have exactly ONE '1' in their binary form.
    //  If a number has only one set bit, then:
    //  n & (n - 1) will be 0
    // Also:
    // - 0 and negative numbers are NOT powers of two.

    bool isPowerOfTwo(int n) 
    {
        if (n <= 0) 
            return false;
        
        return (n & (n - 1)) == 0;
    }
};