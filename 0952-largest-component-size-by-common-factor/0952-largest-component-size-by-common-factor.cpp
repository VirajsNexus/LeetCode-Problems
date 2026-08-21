class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent, parent[x]);
    }

    void unite(vector<int>& parent, vector<int>& size, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b)
            return;

        parent[b] = a;
        size[a] += size[b];
    }

    int largestComponentSize(vector<int>& nums) {

        int n = nums.size();

        vector<int> parent(100001);
        vector<int> size(100001, 1);

        for (int i = 0; i <= 100000; i++)
            parent[i] = i;

        vector<int> factor(100001, -1);

        for (int num : nums) {

            int x = num;

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    if (factor[p] == -1)
                        factor[p] = num;
                    else
                        unite(parent, size, num, factor[p]);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1) {
                if (factor[x] == -1)
                    factor[x] = num;
                else
                    unite(parent, size, num, factor[x]);
            }
        }

        int answer = 1;

        for (int num : nums) {
            answer = max(answer, size[find(parent, num)]);
        }

        return answer;
    }
};