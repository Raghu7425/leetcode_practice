class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();

        // dp[i] = minimum cost to cover days from index i onward
        vector<int> dp(n + 1, 0);

        // Base case
        dp[n] = 0;

        // Fill from back
        for (int i = n - 1; i >= 0; i--) {

            // -------------------------
            // 1-Day Pass
            // -------------------------
            int cost1 = costs[0] + dp[i + 1];

            // -------------------------
            // 7-Day Pass
            // -------------------------
            int next7 = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();

            int cost7 = costs[1] + dp[next7];

            // -------------------------
            // 30-Day Pass
            // -------------------------
            int next30 = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();

            int cost30 = costs[2] + dp[next30];

            // Minimum cost
            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};