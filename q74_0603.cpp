#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<int> ans(temperatures.size(), 0);

        int i = 0;
        for(auto &temp : temperatures){
            while(!minheap.empty() && minheap.top().first < temp){
                ans[minheap.top().second] = i - minheap.top().second;
                minheap.pop();
            }
            minheap.push({temp, i});
            i += 1;
        } 

        return ans;
    }
};

int main(){


    return 0;
}