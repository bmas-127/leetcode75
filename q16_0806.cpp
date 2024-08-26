#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        bool is_one = (nums[0] == 1);
        vector<int> zero_island{};
        vector<int> one_island{};

        if(nums.size() == 1){
            return 1;
        }

        if(is_one){
            zero_island.push_back(0);
        }

        int cons = 0;
        nums.push_back(-1);
        for(auto& num : nums){
            if(is_one){
                if(num == 1){
                    cons += 1;
                }else{
                    one_island.push_back(cons);
                    is_one = false;
                    cons = 1;
                }
            }else{
                if(num == 0){
                    cons += 1;
                }else{
                    zero_island.push_back(cons);
                    is_one = true;
                    cons = 1;
                }
            }
        }

        one_island.push_back(0);

        // for(auto i : one_island){
        //     cout << i << ' ';
        // }
        // cout << endl;
        // for(auto j : zero_island){
        //     cout << j << ' ';
        // }
        // cout << endl;

        int max_sum = 0;
        int j = 0;
        for(int i = 0; i < one_island.size() - 1 && j != zero_island.size(); i ++){
            // cout << "============\n";
            // cout << "i = " << i << endl;
            int remain = k;
            int cur_sum = one_island[i];
            for(j = i + 1; j < zero_island.size(); j ++){
                remain -= zero_island[j];
                // cout << "remain = " << remain << endl;
                if(remain >= 0){
                    cur_sum = cur_sum + one_island[j] + zero_island[j];
                }else{
                    cur_sum = cur_sum + remain + zero_island[j];
                    break;
                }
            }

            if(remain > 0){
                cur_sum += min(zero_island[i], remain);
            }

            // cout << cur_sum << endl;

            max_sum = max(max_sum, cur_sum);
        }

        return max_sum;
    }
};

int main(){
    Solution s;
    vector<int> num1{1,1,1,0,0,0,1,1,1,1,0};
    vector<int> num2{0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};

    cout << s.longestOnes(num1, 2) << endl;

    return 0;
}