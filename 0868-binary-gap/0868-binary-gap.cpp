class Solution {
public:
    int binaryGap(int n) 
    {
        int TotalGap = 0;
        int last = -1;      //position of last(previous) 1
        int current = 0;    //current bit position

        while(n > 0)
        {
            //check if current bit is 1
            if(n % 2 == 1)
            {
                //if this is not the first 1
                if(last != -1)
                {
                    int gap = current - last;

                    if(gap > TotalGap)
                    {
                        TotalGap = gap;
                    }
                }
                // Updating last index
                last = current;
            } 
            //moving to next bit
            n = n /2;
            current++;
        }

        return TotalGap;
    }
};