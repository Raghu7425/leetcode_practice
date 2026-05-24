class Solution {
public:

    long long maxSum(vector<int>& nums, vector<long long>& dp) {

        int n = nums.size();

        for (int j = n - 1; j >= 0; j--) {

            dp[j] = max((long long)nums[j] + dp[j + 2],
                        dp[j + 1]);
        }

        return dp[0];
    }

    int maximumSumSubsequence(vector<int>& nums,
                              vector<vector<int>>& queries) {

        const int MOD = 1e9 + 7;

        int qn = queries.size();
        int n = nums.size();

        vector<long long> dp(n + 2, 0);

        long long res = 0;

        for (int i = 0; i < qn; i++) {

            nums[queries[i][0]] = queries[i][1];

            res = (res + maxSum(nums, dp)) % MOD;
        }

        return (int)res;
    }
};