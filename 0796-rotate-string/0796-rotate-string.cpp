class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        int size = s.size();

        if(size != goal.length())
            return false;

        for(int i = 0; i < size; i++)           // check for nn combinations
        {
            if(s == goal)               
                return true;            // goal found
            
            char start = s[0];


            for(int j = 0; j < size - 1; j++)       // rotate string
            {
                s[j] = s[j + 1];
            }

            s[size - 1] = start;
        }    

        return false;
    }
};