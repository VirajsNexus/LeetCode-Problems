class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        // sort citations in ascending order
        sort(citations.begin(), citations.end());

        int size = citations.size();  // stores size

        for(int i = 0; i < size; i++)
        {
            // number of papers with citations >= citations[i]
            int papers = size - i;

            if(citations[i] >= papers)
            {
                return papers;
            }
        }    

        return 0;
    }
};