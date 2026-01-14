class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        //last index of a string 
        int endIndex = s.size()-1;

        // skipping spaces
        //Finding the start of last word 
        while(endIndex >= 0 && s[endIndex] ==' ')
        {
            --endIndex;
        }   

        //Assigning endIndex to StartIndex
        int StartIndex = endIndex;

        //Lets move backward to find the start of the last word in a string
        while(StartIndex >= 0 && s[StartIndex] != ' ')
        {
            --StartIndex;
        }
        
        //calculate length of the last word
        //we have two indxes at space before last word or at -1 and at the end of initial string
        //Hence, we got the last word by subtracting the StartIndex from endIndex
        //answer of this subtraction gives us the length of last word
        //by iterating backward we can find the last word with that particular number of interations
        return endIndex - StartIndex;  
    }
    
};