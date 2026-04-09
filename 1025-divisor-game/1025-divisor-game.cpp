class Solution {
public:
    bool divisorGame(int n) 
    {
        // If number is even → Alice wins
        // If number is odd  → Alice loses
        return n % 2 == 0;
    }
};