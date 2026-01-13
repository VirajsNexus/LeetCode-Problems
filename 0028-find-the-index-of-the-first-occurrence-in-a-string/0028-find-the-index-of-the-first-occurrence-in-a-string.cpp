class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int HS_size = haystack.size();
        int NDL_size = needle.size();

        //CASE 1: needle not present
        if(NDL_size == 0)
        {
            return 0;
        }

        //CASE 2: Needle is longer than haystack
        if(HS_size < NDL_size)
        {
            return -1;
        }

        //CASE 3: Valid scenarios determine that is needle present in haystack or not
        for(int i = 0; i < HS_size; i++)
        {
            // Checking that is first charcter of incremented character in haystack and Needle is same or not 
            if(haystack[i] == needle[0])
            {
                //create substring of haystack with length of neeedle size
                if(haystack.substr(i,NDL_size) == needle)
                {
                    return i;
                }
            }
        }
        //Needle not present 
        return -1;
    }
};