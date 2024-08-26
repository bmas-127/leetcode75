#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int buyPoint = prices[0];
        int prevHigh = -1;
        
        prices.push_back(-1);
        for(int i = 1; i < prices.size(); i ++){
            if(prices[i] > prices[i-1]){
                if(prevHigh == -1 && prices[i] > buyPoint+ fee){
                    prevHigh = prices[i];
                }

                if(prevHigh != -1 && prices[i] > prevHigh){
                    prevHigh = prices[i];
                }

            }else if(prices[i] < prices[i-1]){
                if(prevHigh != -1 && prices[i] < prevHigh - fee){
                    profit = profit + prevHigh - buyPoint - fee;
                    buyPoint = prices[i]; 
                    prevHigh = -1;
                }else if(prices[i] < buyPoint){
                    buyPoint = prices[i];
                }

            }
        }

        return profit;
    }
};

int main(){
    Solution s;

    return 0;
}