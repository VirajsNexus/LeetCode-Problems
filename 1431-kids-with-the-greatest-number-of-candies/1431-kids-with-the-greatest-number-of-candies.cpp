class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int maxCandies = candies[0];

        // Find maximum candies
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] > maxCandies)
            {
                maxCandies = candies[i];
            }
        }

        vector<bool> result;

        // Check each kid
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxCandies)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;  
    }
};