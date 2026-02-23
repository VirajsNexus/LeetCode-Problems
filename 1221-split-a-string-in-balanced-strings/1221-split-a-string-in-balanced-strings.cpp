class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int count = 0;

        while(s.length() > 0)
        {
            int l = 0;      //stores count of 'L'
            int r = 0;      //stores count of 'R'
            // string temp =""; //stores substring

            for(int i =0; i< s.length(); i++)
            {
                // temp += s[i];   //no need of temp

                if(s[i] == 'L')
                {
                    l++;
                }
                else
                {
                    r++;
                }

                if(l == r)
                {
                    count++;
                    s = s.substr(i + 1);    //removing used part of string
                    break;
                }
            }
        }    
        return count;
    }
};