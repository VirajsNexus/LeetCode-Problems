class Solution {
public:
    int numberOfSpecialChars(string word) 
{
    vector<int> firstUpper(26, -1);
    vector<int> lastLower(26, -1);

    int n = word.length();

    // Store:
    // first occurrence of uppercase
    // last occurrence of lowercase
    for (int i = 0; i < n; i++) 
    {
        char ch = word[i];

        if (ch >= 'a' && ch <= 'z') 
        {
            lastLower[ch - 'a'] = i;
        }
        else 
        {
            int idx = ch - 'A';

            if (firstUpper[idx] == -1) 
            {
                firstUpper[idx] = i;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 26; i++) 
    {
        // both lowercase and uppercase exist
        if (lastLower[i] != -1 && firstUpper[i] != -1) 
        {
            // all lowercase before first uppercase
            if (lastLower[i] < firstUpper[i]) 
            {
                count++;
            }
        }
    }

    return count;
}
};