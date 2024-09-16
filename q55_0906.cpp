#include <vector>
class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        bool prevGreater = true;
        bool nextGreater;

        for(int i = 0; i < nums.size() - 1; i ++){
            nextGreater = nums[i] > nums[i+1];
            if(prevGreater && nextGreater){
                return i;
            }
            prevGreater = !nextGreater;
        }

        return nums.size() - 1;
    }
};