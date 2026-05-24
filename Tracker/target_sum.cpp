class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total_sum = 0;

        for (int x : nums) {
            total_sum += x;
        }

        // Impossible cases
        if (abs(target) > total_sum) {
            return 0;
        }

        // Must be even
        if ((total_sum + target) % 2 != 0) {
            return 0;
        }

        int p = (total_sum + target) / 2;

        int n = nums.size();

        // dp[i][j] = number of ways to make sum j
        // using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));

        // Base case
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= p; j++) {

                // Skip current element
                int skip = dp[i - 1][j];

                // Take current element
                int take = 0;

                if (nums[i - 1] <= j) {
                    take = dp[i - 1][j - nums[i - 1]];
                }

                // Count total ways
                dp[i][j] = skip + take;
            }
        }

        return dp[n][p];
    }
};