class Solution {
public:
    void reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s[start++], s[end--]);
        }
    }

    string reverseWords(string s) 
    {   
        //step 1: reverse whole string
        //step 2: reverse each word
        //step 3: remove extra white-spaces

        int size = s.size();
        
        //step 1 :- 
        reverse(s, 0, size -1);

        //step 2 :-
        int i = 0;
        while(i < size)
        {
            while(i < size && s[i] == ' ')
            {
                i++;                            // Skip white-spaces
            }

            if(i >= size)
                break;

            int j = i;

            while(j < size && s[j] != ' ')
            {
                j++;                             //find word
            }

            reverse(s, i, j - 1);                //reverse word
            
            i = j;                               //move to next word
        }        

        //step 3 :-
        string result = "";
        i = 0;

        while(i < size)
        {
            while(i < size && s[i] == ' ')
            {
                i++;
            }

            if(i >= size)
                break;

            if(!result.empty())
                result += ' ';

            int j = i;

            while(j < size && s[j] != ' ')
            {
                j++;
            }

            result += s.substr(i, j - i);
            i = j;
        }

        return result;
    }
};