class Solution {
public:
    int firstUniqChar(string s) 
    {
        //Hint : use frequency for each character and store it in the array CharFrequency
        int CharFrequency[26] = {0};   

        //Counting frequency of each character  
        for(char& C : s)
        {
            CharFrequency[C - 'a']++;
        }

        //find length of string for interation purpose
        int StringLength = s.size();

        //Finding first character with frequency 1
        for(int i = 0; i < StringLength; i++)
        {
            if(CharFrequency[s[i] - 'a' ] == 1)
            {
                return i;       // returns the index of first unique character
            }
        }
        //no unique character found
        return -1;
    }
};