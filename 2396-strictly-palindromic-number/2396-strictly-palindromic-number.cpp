class Solution {
public:
    bool isStrictlyPalindromic(int n)
    {
        //For base (n - 2), n is always written as "12" → not palindrome → answer always false.
        //n = 1*(n-2) + 2       (quotient and remainder ==> "1" & "2" -----> hence always 12 (not palindromic))
        return false;    
    }
};