class Solution {
public:
    int numTrees(int n) 
    {
        // dp[i] = number of unique BSTs that can be formed using i nodes
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1; // Empty tree
        dp[1] = 1; // Single node

        // from 2 to n nodes
        for (int nodes = 2; nodes <= n; nodes++) 
        {
            for (int root = 1; root <= nodes; root++) 
            {
                int leftSubtreeNodes  = root - 1;
                int rightSubtreeNodes = nodes - root;

                // Total trees = left possibilities * right possibilities
                dp[nodes] += dp[leftSubtreeNodes] * dp[rightSubtreeNodes];
            }
        }

        return dp[n];
    }
};