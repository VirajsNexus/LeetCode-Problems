class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int size = s.size();
        queue<int> q;
        q.push(0);

        vector<bool> visited(size, false);
        visited[0] = true;

        int far = 0;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            if(i  == size - 1)
            {
                return true;
            }

            int initial = max(far, i+ minJump);
            int last = min(size - 1,  i + maxJump);

            for(int j = initial; j <= last; j++)
            {
                if(s[j] == '0' && !visited[j])
                {
                    visited[j] == true;
                    q.push(j);
                }
            }

            far = max(far, last + 1);
        }
        return false;
    }
};