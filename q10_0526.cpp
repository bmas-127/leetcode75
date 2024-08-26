#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> sorted(nums.size());
        auto s = sorted.begin();
        auto e = sorted.end();

        for(auto it = nums.cbegin(); it != nums.cend(); ++it){
            if(*it != 0){
                *s = *it;
                ++ s;
            }else{
                -- e;
                *e = *it;
            }
        }

        nums = move(sorted);
    }
};