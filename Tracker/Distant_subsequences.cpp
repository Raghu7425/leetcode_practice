class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        
        // Use unsigned long long to prevent overflow with very large numbers.
        vector<unsigned long long> dp(n + 1);

        dp[0] = 1;
        for (char c : s) {
            for (int j = n; j >= 1; --j)
                if (t[j - 1] == c)
                    dp[j] += dp[j - 1];
        }
        
        // The final result will be safely within the bounds of unsigned long long.
        return dp[n];
    }
};