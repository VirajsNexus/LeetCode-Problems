class Solution {
public: 
    // Knapsack-01 recursion can be used here

        vector<vector<int>> dp;
        vector<int> cost, time;
        int n;

        int solve(int i, int painted)
        {
            //all walls covered
            if(painted >= n)
                return 0;

            //walls completed but target not achieved yet
            if(i == n)
                return 1e9;

            if(dp[i][painted] != -1)
                return dp[i][painted];
            
            //skip current wall
            int skip = solve(i + 1, painted);

            //Take current wall
            int take = cost[i] + solve(i + 1,painted + time[i] + 1);

            return dp[i][painted] = min(skip, take);
        }

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        //member variables
        this -> cost = cost;
        this -> time = time;

        n = cost.size();

        dp.assign(n, vector<int>(2 * n + 1, -1));

        return solve(0, 0);
    }
};