class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {

        //greedy approach
        int n = cost.size();

        // Sort in descending order
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (cost[j] < cost[j + 1]) 
                {
                    swap(cost[j], cost[j + 1]);
                }
            }
        }

        int totalCost = 0;

        for (int i = 0; i < n; i++) 
        {
            // every 3rd candy is free
            if (i % 3 != 2) 
            { 
                totalCost += cost[i];
            }
        }
        return totalCost;
    }
};