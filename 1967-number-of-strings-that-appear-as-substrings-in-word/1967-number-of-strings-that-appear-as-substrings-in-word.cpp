class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) 
    {
        int count = 0;

        for(int i = 0;  i < patterns.size(); i++)
        {
            string p = patterns[i];
            bool found = false;

            for(int j = 0;  j<= (int)word.size() - (int)p.size(); j++)
            {   
                int k;
                for(k = 0; k < p.size(); k++)
                {
                    if(word[j+k] != p[k])
                        break;
                }
                            
                if(k == p.size())
                {
                    found = true;
                    break;
                }
            }
            if(found == true)
            {
                count++;
            }
        }
        return count;
    }

};