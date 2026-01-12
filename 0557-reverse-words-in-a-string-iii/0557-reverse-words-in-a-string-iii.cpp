class Solution {
public:
    string reverseWords(string s) 
    {
        //create a string stream
        stringstream ss(s);

        string word;        // variable to store string temporary
        string result;      // variable to store final result

        // extracting words from string stream without white space
        while(ss >> word)
        {
            // reverse current word 
            reverse(word.begin(), word.end());

            //append reversed word to result
            result += word;

            // adding space after each word 
            result.push_back(' ');
        }
        //remove unwanted space added after last word
        result.pop_back();

        // now all reversed words in a string stream stored in a result variable with white space separated
        return result;
    }
};