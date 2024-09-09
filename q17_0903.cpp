#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int record = -1;
        int prev = 0;
        int cur = 0;
        bool cont = true;
        bool break_state = 0;
        bool all_zeros = true;

        for(auto& n : nums){
            if(cont){
                if(n == 1){
                    cur += 1;
                }else{
                    record = std::max(record, prev + cur);
                    prev = cur;
                    cur = 0;
                    break_state = true;
                    cont = false;
                    all_zeros = false;
                }
            }else{
                if(break_state){
                    break_state = false;
                    if(n == 1){
                        cur += 1;
                        cont = true;
                    }else{
                        prev = 0;
                    }
                }else if (n == 1){
                    cur += 1;
                    cont = true;
                }
            }
        }

        record = std::max(record, prev + cur) - (int) all_zeros;

        return record;
    }
};