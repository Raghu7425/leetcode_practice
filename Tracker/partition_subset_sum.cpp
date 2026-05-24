class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }

        if(total%2!=0){
            return false;
        }

        int target;
        target=total/2;

        int n = nums.size();

        vector<vector<bool>>dp(n+1,vector(target+1,false));

        for(int i=0;i<=n; i++){
            dp[i][0]=true;
        }

        for(int i=1; i<=n; i++){
            for(int c=1; c<=target; c++){
                bool skip = dp[i-1][c];

                bool take = false;

                if(nums[i-1]<=c){
                    take = dp[i-1][c-nums[i-1]];
                }
                dp[i][c]=skip || take;
            }
        }

        return dp[n][target];
    }
};