#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum, record;
        std::vector<double> doubleNums(nums.size());
        
        std::transform(nums.begin(), nums.end(), doubleNums.begin(),
            [](int val) {return static_cast<double>(val);});

        for(int i = 0; i < k; i ++){
            sum += nums[i];
        }

        record = sum;

        for(int i = k; i < nums.size(); i ++){
            sum = sum + nums[i] - nums[i-k];
            record = std::max(record, sum);
        }
        
        return record / k;
    }
};