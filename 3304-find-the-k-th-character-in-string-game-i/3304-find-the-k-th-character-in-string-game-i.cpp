class Solution {
public:
    char kthCharacter(int k) 
    {
        string word = "a";

        while (word.size() < k) 
        {
            string temp = "";

            // create next characters 
            for (int i = 0; i < word.size(); i++) 
            {
                char c = word[i];

                if (c == 'z')
                    temp += 'a';
                else
                    temp += c + 1;
            }

            // append new string
            word = word + temp;
        }

        return word[k - 1]; // 0-based index
    }
};