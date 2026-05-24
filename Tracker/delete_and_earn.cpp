class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxEL = *max_element(nums.begin(),nums.end());

        vector<int>points(maxEL+1,0);

        for(int x:nums){
            points[x]+=x;
        }

        vector<int>dp(maxEL+3,0);

        for(int i=maxEL; i>=0; i--){
            dp[i]=max(points[i]+dp[i+2],dp[i+1]);
        }

        return dp[0];
    }
};