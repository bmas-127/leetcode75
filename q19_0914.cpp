#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }

        long left = 0;
        long right = 0;

        for(auto &n : nums){
            right += n;
        }

        if(right - nums[0] == 0){
            return 0;
        }

        for(int i = 1; i < nums.size(); i ++){
            left += nums[i];
            right -= nums[i-1];
            if(left == right){
                return i;
            }
        }
        
        return -1;
    }
};