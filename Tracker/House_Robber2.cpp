class Solution {
public:
    int recRob(int start, int end, vector<int>& nums, vector<int>& dp) {

        for (int i = end; i >= start; i--) {
            int take = nums[i] + dp[i + 2];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp1(n + 2, 0);
        int case1 = recRob(0, n - 2, nums, dp1);

        vector<int> dp2(n + 2, 0);
        int case2 = recRob(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};