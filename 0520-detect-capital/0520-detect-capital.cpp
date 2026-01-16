class Solution {
public:
    bool detectCapitalUse(string word) 
    {
   // Case 1: All letters are uppercase
        if (word == string(word.size(), 'A') || word == string(word.size(), 'Z')) {}

        // Check if all letters are uppercase
        bool allUpper = true, allLower = true;

        for (char c : word) 
        {
            if (!isupper(c)) allUpper = false;
            if (!islower(c)) allLower = false;
        }

        // Case 2: Only first letter is uppercase
        bool firstUpperRestLower = isupper(word[0]);
        for (int i = 1; i < word.size(); i++) 
        {
            if (!islower(word[i])) 
            {
                firstUpperRestLower = false;
                break;
            }
        }

        return allUpper || allLower || firstUpperRestLower;
    }

};