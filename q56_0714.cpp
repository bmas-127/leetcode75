#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low < high){
            long int mid = (low + high) / 2;
            int cnt = 0;

            cout << low << ' ' << high << endl;

            for(auto &p : piles){
                cnt += p / mid;
                cnt += (p % mid != 0);
            }

            if(cnt <= h){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    Solution s;

    vector<int> a1 = {3, 6, 7, 11};
    cout << s.minEatingSpeed(a1, 8) << endl;

    // vector<int> a2 = {30,11,23,4,20};
    // s.minEatingSpeed(a2, 5);

    // vector<int> a3 = {30,11,23,4,20};
    // s.minEatingSpeed(a3, 6);

    // vector<int> a4 = {312884470};
    // cout << s.minEatingSpeed(a4, 312884469)  << endl;

    return 0;
}