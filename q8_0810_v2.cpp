#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> next_nums{};

        while(nums.size() > 0){
            print(nums);
            bool next_return = false;
            int prev_num;
            for(int i = 1; i < nums.size(); i ++){
                if(nums[i] > nums[i-1]){
                    next_nums.push_back(nums[i-1]);
                    if(next_return && nums[i] > prev_num){
                        return true;
                    }else if(!next_return){
                        next_return = true;
                        prev_num = nums[i];
                    }
                }
            }
            nums = std::move(next_nums);
        } 



        return false;
    }

    void print(vector<int>& nums){
        for(auto it : nums){
            cout << it << ' ';
        }
        cout << endl;
    }

};



int main(){
    Solution s;
    vector<int> test1{1,5,0,4,1,3};
    vector<int> test2{5,4,3,2,1};
    vector<int> test3{2,1,5,0,4,6};

    cout << s.increasingTriplet(test1) << endl;
    // cout << s.increasingTriplet(test2) << endl;
    // cout << s.increasingTriplet(test3) << endl;

}
