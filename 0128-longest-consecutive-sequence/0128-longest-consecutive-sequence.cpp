class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s;

        // Put all elements into the set
        for (int x : nums) 
        {
            s.insert(x);
        }

        int longest = 0;

        for (int x : s) 
        {

            // x is the beginning of a sequence
            if (s.find(x - 1) == s.end()) 
            {

                int current = x;
                int count = 1;

                // Find consecutive elements
                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }

                if (count > longest) {
                    longest = count;
                }
            }
        }

        return longest;
    }
};