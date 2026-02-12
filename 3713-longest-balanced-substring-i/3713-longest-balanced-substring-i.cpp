class Solution {
public:
        bool checkIsBalanced(vector<int>& freq)
        {
            int common = 0;

            for(int i = 0; i< 26; i++)
            {
                if(freq[i] == 0) continue;

                if(common == 0)
                    common = freq[i];
                else if(freq[i] != common)
                {
                    return false;
                }
            }

            return true;
        }

    int longestBalanced(string s) 
    {
        int n = s.length();

        int max_length = 0;

        for(int i =0; i< n; i++)
        {
            vector<int> freq(26 , 0);       //for all 26 alphabets

            for(int j =i; j< n; j++)
            {
                freq[s[j] - 'a']++;

                //i....j
                //check is balanced?
                if(checkIsBalanced(freq))
                {
                    max_length = max(max_length, j-i+1);
                }            
            } 
        }

        return max_length;

    }
};