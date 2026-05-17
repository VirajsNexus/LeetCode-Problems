class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n = arr.size();
        queue<int> q;
        q.push(start);

        vector<bool> visited(n, false);
        visited[start] = true;

        while (!q.empty()) 
        {
            int i = q.front();
            q.pop();

            // If current index contains 0, answer is true
            if (arr[i] == 0)
                return true;

            // Jump to the right
            int right = i + arr[i];
            if (right < n && !visited[right]) 
            {
                visited[right] = true;
                q.push(right);
            }

            // Jump to the left
            int left = i - arr[i];
            if (left >= 0 && !visited[left]) 
            {
                visited[left] = true;
                q.push(left);
            }
        }

        // No index with value 0 can be reached
        return false;
    }
};