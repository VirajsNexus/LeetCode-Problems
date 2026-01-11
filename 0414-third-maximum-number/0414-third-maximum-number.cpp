class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        // initialize 3 variables for first 3 max element
        long First_Max = LONG_MIN;
        long Second_Max = LONG_MIN;
        long Third_Max = LONG_MIN;

        int result;     // for storing result

        //Iterate through all elements
        for(int num : nums)
        {
            //skip duplicates (we only want distinct maximum value)
            if(num == First_Max || num == Second_Max || num == Third_Max)
            {
                continue;
            }
            //update three max values based on the current number 
            if(num > First_Max)
            {
                //current number is new First max number
                Third_Max = Second_Max;
                Second_Max = First_Max;
                First_Max = num;
            }

            else if(num > Second_Max)
            {
                //current number is second max number
                Third_Max = Second_Max;
                Second_Max = num;
            }
            else if(num > Third_Max)
            {
                //current number is 3rd max number
                Third_Max = num;
            }
        }

        // Lets determine the number to be return
        // Returning third maximum if it exists, otherwise return the maximum
        // If thirdMax is still LONG_MIN, it means we have less than 3 distinct numbers

        if(Third_Max != LONG_MIN)
        {
            result = Third_Max;
        }
        else
        {
            result = First_Max;
        }

        return result;
    }
};