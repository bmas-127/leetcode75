#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<bool> search(nums.size(), true);

        // for (auto n : nums){
        //     cout << n << ' ';
        // }
        // cout << endl << endl;

        for(int i = 0; i < nums.size(); i ++){
            if(search[i]){
                int j = i;

                while(j < nums.size() && j != -1){
                    int next_bigger = find_next_bigger(nums, j, nums[i]);
                    // cout << next_bigger << endl;
                    if(next_bigger != -1){
                        int next = find_next_bigger(nums, next_bigger, nums[next_bigger]);
                        if(next != -1){
                            return true;
                        }else{
                            search[next_bigger] = false;
                        }
                    }
                    j = next_bigger;
                }
                


                // cout << "===============\n";
            }
        }
        
        return false;
    }

    int find_next_bigger(vector<int> &nums, int start, int cur){
        for(int i = start + 1; i < nums.size(); i ++){
            if(nums[i] > cur){
                return i;
            }
        }

        return -1;
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
