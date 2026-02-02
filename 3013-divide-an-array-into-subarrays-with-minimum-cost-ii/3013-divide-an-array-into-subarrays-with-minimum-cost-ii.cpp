class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) 
    {
       --k;  // nums[0] is always taken, so we only need k more numbers

        multiset<int> left, right;
        long long sum = 0;

        // Add the first window elements (from index 1 to dist+1)
        for (int i = 1; i <= dist + 1; i++) 
        {
            left.insert(nums[i]);
            sum += nums[i];
        }

        // Keep only the k smallest numbers in left
        // Move the bigger ones to right
        while (left.size() > k) 
        {
            auto it = prev(left.end());   // biggest number in left
            sum -= *it;
            right.insert(*it);
            left.erase(it);
        }

        // This stores the minimum sum we have seen
        long long ans = sum;

        // Slide the window across the array
        for (int i = dist + 2; i < nums.size(); i++) 
        {

            int out = nums[i - dist - 1]; // number going out of the window
            int in  = nums[i];            // number coming into the window

            // Remove the outgoing number
            auto itLeft = left.find(out);
            if (itLeft != left.end()) 
            {
                // It was one of the k smallest
                sum -= out;
                left.erase(itLeft);
            } 
            else 
            {
                // It was in the bigger numbers set
                right.erase(right.find(out));
            }

            // Add the incoming number
            // If it is big, put it in right
            // Otherwise, put it in left and add to sum
            if (!left.empty() && in > *prev(left.end())) 
            {
                right.insert(in);
            } 
            else 
            {
                left.insert(in);
                sum += in;
            }

            // If left has too few numbers, take the smallest from right
            if (left.size() < k) 
            {
                auto it = right.begin();
                sum += *it;
                left.insert(*it);
                right.erase(it);
            }

            // If left has too many numbers, move the biggest to right
            if (left.size() > k) 
            {
                auto it = prev(left.end());
                sum -= *it;
                right.insert(*it);
                left.erase(it);
            }

            // Update the minimum sum found so far
            ans = min(ans, sum);
        }

        // nums[0] must always be included in the cost
        return ans + nums[0];
    }
};