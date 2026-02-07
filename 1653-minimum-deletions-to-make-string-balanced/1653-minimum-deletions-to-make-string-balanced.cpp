class Solution {
public:
    int minimumDeletions(string s) 
    {
        int deletions = 0;
        int bCount = 0;

        for (char c : s) 
        {
            if (c == 'b') 
            {
                bCount++; // Found a 'b', track it as a potential deletion candidate
            } 
            else if (bCount > 0) 
            {
                // Found an 'a' after at least one 'b'
                // We must delete either this 'a' or one of the previous 'b's
                deletions++; 
                bCount--; // "Remove" one 'b' from the pool since it's now paired with this 'a'
            }
        }

        return deletions;
    }
};