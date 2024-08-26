#include <iostream>
#include <vector>

using namespace std;

class Solution {
        vector<int> zero_island{};
        vector<int> one_island{};
public:
    int longestOnes(vector<int>& nums, int k) {
        bool is_one = (nums[0] == 1);

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

        // print();
        return find_max_length(k);
    }

    int find_max_length(int k){
        int begin = 0;
        int end = begin + 1;
        int remain = k;
        int cur_sum = one_island[0];
        int max_sum = -1;

        // first round
        bool finish = true;
        for(int i = 1; i < zero_island.size(); i ++){
            remain -= zero_island[i];
            if(remain < 0){
                finish = false;
                remain += zero_island[i];
                break;
            }
            cur_sum = cur_sum + one_island[i] + zero_island[i];
            end ++;
        }

        if(finish && remain > 0){
            return cur_sum + std::min(zero_island[0], remain);
        }
        max_sum = cur_sum + remain;

        while(end < zero_island.size()){
            cur_sum = cur_sum - zero_island[begin+1] - one_island[begin];
            remain += zero_island[++begin];

            while(end < zero_island.size()){
                remain -= zero_island[end];
                if(remain < 0){
                    remain += zero_island[end];
                    break;
                }
                cur_sum = cur_sum + zero_island[end] + one_island[end];
                end ++;
            }

            max_sum = std::max(max_sum, cur_sum + remain);
        }

        return max_sum;
    }

    void print(){
        for(auto i : one_island){
            cout << i << ' ';
        }
        cout << endl;
        for(auto j : zero_island){
            cout << j << ' ';
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int> num1{1,1,1,0,0,0,1,1,1,1,0};
    vector<int> num2{0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};

    cout << s.longestOnes(num1, 2) << endl;

    return 0;
}