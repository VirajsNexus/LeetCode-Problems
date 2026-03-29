class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 0: Basic validation
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }
        
        // Step 1: Build string
        string word(n, '?');
        char ch = 'a';
        
        for (int i = 0; i < n; i++) {
            if (word[i] == '?') {
                if (ch > 'z') return ""; // only lowercase allowed
                
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = ch;
                    }
                }
                ch++;
            }
        }
        
        // Step 2: Validate LCP matrix
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }
        
        return word;
    }
};