class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum = 0;

        for(int x:stones){
            total_sum+=x;
        }
        int target = total_sum/2;
        vector<bool>dp(target+1,false);

        dp[0]=true;

        for(int stone:stones){
            for(int s= target; s>=stone; s--){
                dp[s]=dp[s]|| dp[s-stone];
            }
        }


        for(int s=target; s>=0; s--){
            if(dp[s]){
                return total_sum-2*s;
            }
        }

        return 0;


    }
};