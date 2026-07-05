class Solution {
public:
    bool check(string s, string t, bool rev) {
        if (rev) {
            reverse(s.begin(), s.end());
            reverse(t.begin(), t.end());
        }

        int n = s.size(), m = t.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if (i == n) return true;

        int miss = i;

        for (char c = 'a'; c <= 'z'; c++) {
            string temp = s;
            temp[miss] = c;

            int p = 0, q = 0;
            while (p < n && q < m) {
                if (temp[p] == t[q]) {
                    p++;
                    q++;
                } else {
                    q++;
                }
            }

            if (p == n) return true;
        }

        return false;
    }

    bool canMakeSubsequence(string s, string t) {
        return check(s, t, false) || check(s, t, true);
    }
};