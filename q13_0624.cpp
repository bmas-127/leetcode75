#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;

        int eq_num = 0;

        while(start < end){
            int sum = nums[start] + nums[end];

            if(sum == k){
                eq_num ++;
                start ++;
                end --;
            }else if(sum < k){
                start ++;
            }else{
                end --;
            }
        }

        return eq_num;
    }
};