#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::pair<int, int>> numsPair(nums1.size());

        for(int i = 0; i < nums1.size(); i ++){
            numsPair[i].first = nums1[i];
            numsPair[i].second = nums2[i];
        }

        sort(numsPair.begin(), numsPair.end(), [](auto p1, auto p2){
            return p1.second < p2.second;
        });

        int end = numsPair.size() - 1;
        long long sum = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


        while(end >= (int) numsPair.size()-k){
            sum += numsPair[end].first;
            minHeap.push(numsPair[end].first);
            end --;
        }


        long long maxValue = sum * numsPair[end+1].second;
        

        while(end >= 0){
            if(numsPair[end].first > minHeap.top()){
                // cout << "here" << endl;
                sum -= minHeap.top();
                sum += numsPair[end].first;
                minHeap.pop();
                minHeap.push(numsPair[end].first);
                maxValue = std::max(maxValue, numsPair[end].second * sum);
            }

            end --;
        }


        return maxValue;
    }
};

int main(){
    vector<int> a {2, 1, 14, 2};
    vector<int> b {11, 7, 13, 6};
    Solution s;

    cout << s.maxScore(a, b, 3) << endl;

    return 0;
}