class Solution {
public:
    int fib(int n) 
    {
        //if n is 0 or 1 return n itself
        if(n <= 1)
        {
            return n;
        }    
        
        // recursive call : addition of previous two numbers
        return fib(n-1) + fib(n - 2);
    }
};