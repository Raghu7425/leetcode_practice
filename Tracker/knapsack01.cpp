class Solution {
public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // i -> number of items considered
        for(int i = 1; i <= n; i++) {

            // w -> current bag capacity
            for(int w = 0; w <= W; w++) {

                // OPTION 1 : skip current item
                int skip = dp[i - 1][w];

                // OPTION 2 : take current item
                int take = 0;

                // actual item index = i-1
                if(wt[i - 1] <= w) {

                    take = val[i - 1]
                         + dp[i - 1][w - wt[i - 1]];
                }

                // choose best option
                dp[i][w] = max(take, skip);
            }
        }

        return dp[n][W];
    }
};