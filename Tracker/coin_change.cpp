class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, amount+1);

        dp[0]=0;

        for(int x: coins){  
            for(int amt=x; amt<=amount; amt++){
                dp[amt]=min(dp[amt], 1+dp[amt-x]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};