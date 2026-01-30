class Solution {
public:

//Derive Helper function to convert roman numbers
    int value(char c)
    {
        switch (c)
        {
            case 'I' : return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;       //for invalid case
    }
    int romanToInt(string s) 
    {
        int result = 0;     //variable to store final result
        //Traversing through roman string from left to right
        for(int i = 0; i< s.size(); i++)
        {
            //store value of current roman number character 
            int current = value(s[i]);

            //Storing value of next roman numeral character in variable 'Next'
            int Next;
            if(i+1 < s.size())
            {
                Next = value(s[i +1]);
            }
            //If we are at last charcter(return 0)
            else
            {
                Next = 0;
            }

            //Actual conversion steps and decision making for addition or subtraction operations
            if(current < Next)   //current value smaller than next value represents subtraction
            {
                result -= current;
            }
            else                //normal case means addition to be performed
            {
                result += current;
            }
        }    
        //return final result
        return result;
    }
};