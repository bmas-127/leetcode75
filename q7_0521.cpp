#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long int product = 1;
        for(auto it = nums.cbegin(); it != nums.cend(); ++it){
            if(*it == 0){
                return move(zeroHandling(nums, it, product));
            }else{
                product *= *it;
            }
        }

        for(auto it = nums.begin(); it != nums.end(); ++it){
            *it = product / *it;
        }

        return nums;
    }

    vector<int> zeroHandling(vector<int>& nums, vector<int>::const_iterator start, long int product){
        bool second_zero = false;
        for(auto it = start + 1; it != nums.cend(); it ++){
            if(*it == 0){
                second_zero = true;
                break;
            }else{
                product *= *it;
            }
        }

        vector<int> rnums(nums.size(), 0);
        if(second_zero == false){
            rnums[start - nums.cbegin()] = product;
        }

        return move(rnums);
    }
};
