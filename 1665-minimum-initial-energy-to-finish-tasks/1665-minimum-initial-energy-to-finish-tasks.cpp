class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Step 1: Sort tasks (minimum - actual) in descending order.
        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[1] - a[0]) > (b[1] - b[0]);
            });

        // Step 2: Start with 0 energy.
        int energy = 0;

        // Step 3: Process each task.
        for (int i = 0; i < tasks.size(); i++) 
        {
            int actual = tasks[i][0];   // energy spent
            int minimum = tasks[i][1];  // minimum energy needed to start

            // need enough energy before starting task
            if (energy < minimum) 
            {
                energy = minimum;
            }

            // Task completed so, energy decreases by actual.
            energy = energy - actual;
        }

        // Step 4: 
        // Initial energy = remaining energy + total actual spent.
        int totalActual = 0;
        for (int i = 0; i < tasks.size(); i++) 
        {
            totalActual += tasks[i][0];
        }

        return energy + totalActual;
    }
};