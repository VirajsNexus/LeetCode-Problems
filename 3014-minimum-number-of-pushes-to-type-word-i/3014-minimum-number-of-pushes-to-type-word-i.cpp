class Solution {
public:
    int minimumPushes(string word) 
    {
        int size = word.length();
        int result = 0;

        for(int i = 0; i < size; i++)
        {
            result += (i / 8) + 1;
        }
    return result;
    }
};