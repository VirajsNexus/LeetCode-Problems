class Solution
{
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k)
    {
        vector<vector<int>> ans;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i = 0; i < n1 && i < k; i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k > 0 && !pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();

            int i = curr[1];
            int j = curr[2];

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < n2)
            {
                pq.push(
                {
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }

            k--;
        }

        return ans;
    }
};