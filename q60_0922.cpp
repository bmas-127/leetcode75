#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = std::min(cost[0], cost[1]);

        for(int i = 2; i < cost.size(); i ++){
            dp[i] = 
        }
        
    }
};