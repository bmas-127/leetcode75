#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int begin = 0;
        int end = nums.size();
        k --;

        while(true){
            // printf("=========\n");
            // cout << nums[0] << endl;
            int mid = partition(nums, begin, end);
            // for(int i = begin; i < end; i ++){
            //     cout << nums[i] << ' ';
            // }
            // cout << endl;

            if(mid > k){
                end = mid;
            }else if(mid < k){
                begin = mid + 1;
            }else{
                return nums[mid];
            }
        }
    }

    int partition(vector<int>& nums, int begin, int end){
        int mid = nums[begin];
        int pivot = begin;

        for(int i = begin + 1; i < end; i ++){
            if(nums[i] > mid){
                nums[pivot++] = nums[i];
                nums[i] = nums[pivot];
            }
        }

        nums[pivot] = mid;

        return pivot;
    }
};

int main(){
    Solution s;
    vector<int> a{3,2,1,5,6,4};
    cout << s.findKthLargest(a, 2) << endl;


    vector<int> b{3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(b, 4) << endl;

    return 0;
}