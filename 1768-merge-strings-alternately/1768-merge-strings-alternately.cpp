class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int length1 = word1.size();
        int length2 = word2.size();

        string result;   // variable to store merged string

        // we dont know that which string has longer length so we will use or operator to iterate till all characters in both strings
        for(int i = 0; i < length1 || i < length2; i++)
        {
            // now, appending of characters of strings to be selected based on " is the index of them is within the length of respective word? "

            // applying condition to first word
            if(i < length1)
            {
                result += word1[i];
            }
            
            // applying condition to second word
            if(i < length2)
            {
                result += word2[i];
            }
        }   

        return result;
    }
};