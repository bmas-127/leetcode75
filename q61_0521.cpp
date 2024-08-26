#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> best_rob_nb(nums.size());
        vector<int> best_rob_wb(nums.size());

        if(nums.size() == 0){
            return 0;
        }

        best_rob_nb[0] = 0;
        best_rob_wb[0] = nums[0];

        if(nums.size() == 1){
            return nums[0];
        }

        best_rob_nb[1] = nums[0];
        best_rob_wb[1] = nums[1];

        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        best_rob_nb[2] = max(nums[0], nums[1]);
        best_rob_wb[2] = nums[0] + nums[2]; 

        
        for(int i = 3; i < nums.size(); i ++){
            best_rob_wb[i] = max(best_rob_wb[i - 2], best_rob_wb[i - 3]) + nums[i];
            best_rob_nb[i] = best_rob_wb[i - 1];
        }

        return max(best_rob_nb[nums.size()-1], best_rob_wb[nums.size()-1]);
    }
};

int main(){


    return 0;
}