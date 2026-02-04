class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) 
    {
        int n = nums.size();
        long long INF = 1e18;   //1 quintillion (large number)
        
        // DP States:
        long long up1 = nums[0]; // Stage 1: First Climb
        long long down = -INF;   // Stage 2: Valley
        long long up2 = -INF;    // Stage 3: Final Climb
        
        long long globalMax = -INF;

        for (int i = 1; i < n; ++i) {
            int curr = nums[i];
            int prev = nums[i-1];
            
            long long next_up1, next_down, next_up2;

            if (curr > prev) { // --- GOING UP ---
                
                // 1. Extend First Climb
                next_up1 = up1 + curr;
                
                // 2. Impossible (Can't go down)
                next_down = -INF; 
                
                // 3. Final Climb: Extend OR Start from Valley
                if (down != -INF) 
                    next_up2 = max(up2, down) + curr;
                else if (up2 != -INF)
                    next_up2 = up2 + curr;
                else 
                    next_up2 = -INF;
            } 
            else if (curr < prev) { // --- GOING DOWN ---

                // 1. Broken Climb: Reset to new start
                next_up1 = curr; 
                
                // 2. Valley: Extend OR Start from Valid Peak
                long long start_descent = -INF;
                
                // Check if previous index was a real Peak
                if (i >= 2 && nums[i-1] > nums[i-2]) {
                    start_descent = up1 + curr;
                }
                
                long long continue_descent = (down != -INF) ? down + curr : -INF;
                next_down = max(continue_descent, start_descent);

                // 3. Impossible (Can't go up)
                next_up2 = -INF;
            } 
            else { // --- FLAT ---
                // Reset all. Start fresh.
                next_up1 = curr; 
                next_down = -INF;
                next_up2 = -INF;
            }

            // Update states
            up1 = next_up1;
            down = next_down;
            up2 = next_up2;

            // Check if full shape exists
            if (up2 != -INF) {
                globalMax = max(globalMax, up2);
            }
        }

        return globalMax;
    }
};